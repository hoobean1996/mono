package net

import (
	"context"
	"log"
	"net"
	"sync"
	"sync/atomic"
	"time"

	"liquid.io/go/pkg/utils"
)

type Conn interface {
	Send(ctx context.Context, data []byte) error
	Recv(ctx context.Context) ([]byte, error)

	Close() error
}

type conn struct {
	ctx    context.Context
	cancel context.CancelFunc

	mu *sync.Mutex
	wg *sync.WaitGroup

	network  string
	addr     string
	isClient bool
	protocol TxpProtocol

	c net.Conn
	// closed indicates whether the connection is available.
	closed uint32
	// recvs is the channel for those `incoming` packets.
	// handleRecv -> recvs -> Application
	// handleRecv -> close(recvs)
	recvs chan []byte
	// sends is the channel for those `outgoing` packets.
	// Application -> sends -> handleSend
	// Application -> close(sends)
	sends chan []byte
}

func (cc *conn) handleRecv() {
	log.Printf("G=%d#handleRecv enter", utils.CurrentGID())
	defer log.Printf("G=%d#handleRecv exit", utils.CurrentGID())
	defer cc.wg.Done()
	for {
		select {
		case <-cc.ctx.Done():
			{
				atomic.StoreUint32(&cc.closed, 1)
				close(cc.recvs)
				goto ExitHandleRecv
			}
		default:
		}
		data, err := cc.protocol.txpReadFunc(cc.c)
		if err != nil {
			atomic.StoreUint32(&cc.closed, 1)
			close(cc.recvs)
			goto ExitHandleRecv
		}
		cc.recvs <- data
	}
ExitHandleRecv:
}

func (cc *conn) handleSend() {
	log.Printf("G=%d#handleSend enter", utils.CurrentGID())
	defer log.Printf("G=%d#handleSend exit", utils.CurrentGID())
	defer cc.wg.Done()
	for {
		select {
		case <-cc.ctx.Done():
			{
				atomic.StoreUint32(&cc.closed, 1)
				goto ExitHandleRead
			}
		case data, ok := <-cc.sends:
			{
				if !ok {
					goto ExitHandleRead
				}
				err := cc.protocol.txpWriteFunc(cc.c, data)
				if err != nil {
					atomic.StoreUint32(&cc.closed, 1)
					break
				}
			}
		}
	}
ExitHandleRead:
}

func (cc *conn) isClosed() bool {
	return atomic.LoadUint32(&cc.closed) == 1
}

func (cc *conn) Send(ctx context.Context, data []byte) error {
	if cc.isClosed() {
		close(cc.sends)
		return ErrConnClosed
	}

	if t, ok := ctx.Deadline(); !ok {
		select {
		case cc.sends <- data:
			{
				return nil
			}
		}
	} else {
		select {
		case <-ctx.Done():
			{
				return ErrSendTimeout
			}
		case <-time.After(t.Sub(time.Now())):
			{
				return ErrSendTimeout
			}
		case cc.sends <- data:
			{
				return nil
			}
		}
	}
}

func (cc *conn) Recv(ctx context.Context) ([]byte, error) {
	if cc.isClosed() {
		return nil, ErrConnClosed
	}

	if t, ok := ctx.Deadline(); !ok {
		select {
		case data, ok := <-cc.recvs:
			{
				if !ok {
					return nil, ErrConnClosed
				}
				return data, nil
			}
		}
	} else {
		select {
		case <-ctx.Done():
			{
				return nil, ErrRecvTimeout
			}
		case data, ok := <-cc.recvs:
			{
				if !ok {
					return nil, ErrConnClosed
				}
				return data, nil
			}
		case <-time.After(t.Sub(time.Now())):
			{
				return nil, ErrRecvTimeout
			}
		}
	}
}

func (cc *conn) Close() error {
	atomic.StoreUint32(&cc.closed, 1)
	cc.cancel()
	return cc.c.Close()
}
