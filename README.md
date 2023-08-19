# mono

monorepo is used to contain all of my projects build with bazel.

## why mono

1. mono repo can share the same build infrastructure
2. all project can benifit from any shared tools improvement

## project structure

all projects are working in progress.

- c

  - zos: a simple Operating System written before

- cc

  - cetty: a netty-like networking library, the async approach is `callback`
  - coro: a networking library that based on C++ 20 co_await, co_return, co_yield
  - kv: a small key-value engine
  - graphd: a graphql server

- go

  - asyncd: a asynchronous task queue service
  - configd: a config manager for microservice
  - routingd: a service registry and service discovery service

- idl

  - protobufs: repositry for all protobufs definitions

- leetcode

  - alg: leetcode question solutions
  - wiki: some key template in algorithm

- ocaml

  - thriftc: try ocaml menlir to build compiler for thrift

- py

  - currently no idea what will do, just can build with bazel

- www

  - the web ui for all project, build with bazel

- xplat
  - will add some shared tools inside
