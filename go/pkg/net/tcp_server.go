package net

import (
	"context"
	"errors"
	gonet "net"
)

type TCPServer struct {
	ctx    context.Context
	cancel context.CancelFunc

	opts *tcpServerOption
}

func (srv *TCPServer) Serve() error {
	var ll gonet.Listener

	l, err := gonet.Listen("tcp", srv.opts.listenAddr)
	if err != nil {
		return err
	} else {
		ll = l
	}

	for {
		c, err := ll.Accept()
		if err != nil {
			return err
		}

		cc := Upgrade(srv.ctx, srv.cancel, c, "tcp", srv.opts.listenAddr)
		go srv.opts.onNewConnectionHandler(cc)
	}
}

func (srv *TCPServer) Shutdown() error {
	return nil
}

func NewTCPServer(opts ...TCPServerOptions) *TCPServer {
	ctx, cancel := context.WithCancel(context.Background())

	srv := &TCPServer{
		ctx:    ctx,
		cancel: cancel,
		opts:   &tcpServerOption{},
	}

	for _, opt := range opts {
		opt(srv.opts)
	}

	if srv.opts.onNewConnectionHandler == nil {
		panic(errors.New("on_new_connection_handler is set to defaultOnNewConnectionHandler"))
	}

	return srv
}
