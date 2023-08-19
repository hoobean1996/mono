package rpc

import "context"

type Client interface {
	// Call a method registered in remote server, then waits for the response in the given time.
	Call(ctx context.Context, name string, request interface{}) (interface{}, error)

	// AsyncCall is Call in asynchronous mode, which would not care about the response.
	AsyncCall(ctx context.Context, name string, request interface{}) error

	// Close the Client gracefully.
	Close() error
}
