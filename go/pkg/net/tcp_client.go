package net

import "context"

type TCPClient struct {
	ctx    context.Context
	cancel context.CancelFunc
}
