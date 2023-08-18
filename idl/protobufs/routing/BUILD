load("@rules_proto//proto:defs.bzl", "proto_library")
load("@io_bazel_rules_go//proto:def.bzl", "go_proto_library")
load("@io_bazel_rules_go//go:def.bzl", "go_library")

proto_library(
    name = "routing_proto",
    srcs = ["routing.proto"],
    visibility = ["//visibility:public"],
)

go_proto_library(
    name = "routing_go_proto",
    compilers = ["@io_bazel_rules_go//proto:go_grpc"],
    importpath = "liquid.io/idl/protobufs/gen/routing",
    proto = ":routing_proto",
    visibility = ["//visibility:public"],
)

go_library(
    name = "librouting",
    embed = [":routing_go_proto"],
    importpath = "liquid.io/idl/protobufs/gen/routing",
    visibility = ["//visibility:public"],
)
