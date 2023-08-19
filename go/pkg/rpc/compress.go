package rpc

type Compressor interface {
	Compress([]byte) ([]byte, error)
	Depress([]byte) ([]byte, error)
}
