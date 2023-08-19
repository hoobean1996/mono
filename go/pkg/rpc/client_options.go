package rpc

// ClientOption defines how should a Client behave.
type ClientOption func(option *clientOption)

type clientOption struct{}
