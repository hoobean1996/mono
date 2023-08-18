package main

import (
	"context"
	"log"
	"net"
	"net/http"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promhttp"
	"liquid.io/idl/protobufs/gen/routing"

	"google.golang.org/grpc"
)

type Server struct {
}

func (s *Server) Register(context.Context, *routing.RegisterRequest) (*routing.RegisterResponse, error) {
	return &routing.RegisterResponse{}, nil
}

func (s *Server) Deregister(context.Context, *routing.DeregisterRequest) (*routing.DeregisterResponse, error) {
	return &routing.DeregisterResponse{}, nil
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
	log.Println("RoutingD bootstrapped")
	lis, err := net.Listen("tcp", "localhost:50051")
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	grpcServer := grpc.NewServer()
	x := &Server{}
	routing.RegisterRoutingDServer(grpcServer, x)

	log.Println("grpc llisten")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %s", err)
	}
}
