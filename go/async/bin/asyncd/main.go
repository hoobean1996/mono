package main

import (
	"context"
	"log"
	"net"
	"net/http"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promhttp"
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
	vc := prometheus.NewCounter(prometheus.CounterOpts{
		Name: "view_counter",
		Help: "how many people vied this site.",
	})
	prometheus.MustRegister(vc)

	go func() {
		http.Handle("/metrics", promhttp.Handler())
		http.ListenAndServe(":2112", nil)
	}()
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
