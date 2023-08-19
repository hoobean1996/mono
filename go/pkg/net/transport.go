// Package net implement the function to read from and write to TCP transport layer
// By default, we would only consider TCP socket and unix socket.
// For each packet, we have 4 bytes as a uint32 to be the packet length before the packet
package net

import (
	"encoding/binary"
	"io"
)

// TxpProtocol defines how to read/write data to net.Conn.
type TxpProtocol interface {
	txpReadFunc(r io.Reader) ([]byte, error)
	txpWriteFunc(w io.Writer, data []byte) error
}

type basicProtocol struct {
	// basicProtocol is a fixed-length-prefix protocol
	// 4 bytes is the total payload length
	// the following bytes are belonging to the payload.
}

func (protocol basicProtocol) txpReadFunc(r io.Reader) ([]byte, error) {
	lengthBytes := make([]byte, 4)
	_, err := io.ReadFull(r, lengthBytes)
	if err != nil {
		return nil, err
	}
	length := binary.LittleEndian.Uint32(lengthBytes)
	data := make([]byte, length)
	_, err = io.ReadFull(r, data)
	if err != nil {
		return nil, err
	}
	return data, nil
}

func (protocol basicProtocol) txpWriteFunc(w io.Writer, data []byte) error {
	length := len(data)
	lengthBytes := make([]byte, 4)
	binary.LittleEndian.PutUint32(lengthBytes, uint32(length))
	buffer := make([]byte, 4+length)
	copy(buffer, lengthBytes)
	copy(buffer[4:], data)
	if _, err := w.Write(buffer); err != nil {
		return err
	}
	return nil
}
