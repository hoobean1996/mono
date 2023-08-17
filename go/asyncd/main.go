package main

import (
	"context"
	"log"
	"net"

	"liquid.io/idl/protobufs/gen/async"

	"google.golang.org/grpc"
)

type Server struct {
	async.AsyncDServer
}

func (s *Server) Schedule(ctx context.Context, in *async.AsyncRequest) (*async.AsyncResponse, error) {
	log.Printf("Receive message body from client: %s", in.Name)
	return &async.AsyncResponse{Name: "Hello From the Server!"}, nil
}

func main() {
	log.Println("AsyncD bootstrapped")
	lis, err := net.Listen("tcp", "localhost:50051")
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	grpcServer := grpc.NewServer()
	x := &Server{}
	async.RegisterAsyncDServer(grpcServer, x)

	log.Println("grpc llisten")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %s", err)
	}
}
