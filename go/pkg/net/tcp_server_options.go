package net

type TCPServerOptions func(*tcpServerOption)
type tcpServerOption struct {
	listenAddr string

	onNewConnectionHandler func(Conn)
	onRecvDataHandler      func([]byte)
}

func WithListenAddress(addr string) TCPServerOptions {
	return func(option *tcpServerOption) {
		option.listenAddr = addr
	}
}

func WithOnNewConnectionHandler(onNewConnectionHandler func(Conn)) TCPServerOptions {
	return func(option *tcpServerOption) {
		option.onNewConnectionHandler = onNewConnectionHandler
	}
}
