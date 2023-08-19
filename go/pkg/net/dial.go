package net

import (
	"context"
	"net"
	"sync"
)

// Dial is used to create a new Connection for the client.
func Dial(network string, addr string) (Conn, error) {
	c, err := net.Dial(network, addr)
	if err != nil {
		return nil, err
	}

	ctx, cancel := context.WithCancel(context.Background())

	cc := &conn{
		ctx:      ctx,
		cancel:   cancel,
		c:        c,
		mu:       &sync.Mutex{},
		wg:       &sync.WaitGroup{},
		network:  network,
		addr:     addr,
		isClient: true,
		protocol: basicProtocol{},
		closed:   0,
		recvs:    make(chan []byte, 1024),
		sends:    make(chan []byte, 1024),
	}

	cc.wg.Add(2)

	go cc.handleSend()
	go cc.handleRecv()

	return cc, nil
}

// Upgrade is used to upgrade a TCP net.Conn to be our Conn for the server.
func Upgrade(ctx context.Context, cancel context.CancelFunc, c net.Conn, network string, addr string) Conn {
	cc := &conn{
		ctx:      ctx,
		cancel:   cancel,
		c:        c,
		mu:       &sync.Mutex{},
		wg:       &sync.WaitGroup{},
		network:  network,
		addr:     addr,
		isClient: false,
		protocol: basicProtocol{},
		closed:   0,
		recvs:    make(chan []byte, 1024),
		sends:    make(chan []byte, 1024),
	}
	cc.wg.Add(2)
	go cc.handleSend()
	go cc.handleRecv()
	return cc
}
