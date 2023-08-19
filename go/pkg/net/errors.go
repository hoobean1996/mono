package net

import "errors"

var (
	// ErrConnClosed indicates the connection is unavailable.
	ErrConnClosed = errors.New("connection closed")

	ErrSendTimeout = errors.New("connection send timed out")

	ErrRecvTimeout = errors.New("connection recv timed out")
)
