package main

import (
	"context"
	"fmt"
	"log"

	"google.golang.org/grpc"
	"liquid.io/idl/protobufs/gen/async"
)

func main() {
	conn, err := grpc.Dial("localhost:50051", grpc.WithInsecure())
	if err != nil {
		log.Fatalf("Failed to connect: %v", err)
	}
	defer conn.Close()

	client := async.NewAsyncDClient(conn)

	req := &async.AsyncRequest{
		Name: "Alice",
	}

	resp, err := client.Schedule(context.Background(), req)
	if err != nil {
		log.Fatalf("Error calling SayHello: %v", err)
	}

	fmt.Printf("Response: %s\n", resp.Name)

}
