package rpc

// Codec defines how to encode and decode bytes.
type Codec interface {
	Marshal(v interface{}) ([]byte, error)

	Unmarshal(data []byte, v interface{}) error

	String() string
}
