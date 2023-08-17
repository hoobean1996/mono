load("@rules_proto//proto:defs.bzl", "proto_library")
load("@io_bazel_rules_go//proto:def.bzl", "go_proto_library")
load("@io_bazel_rules_go//go:def.bzl", "go_library")

proto_library(
    name = "async_proto",
    srcs = ["async.proto"],
    visibility = ["//visibility:public"],
)

go_proto_library(
    name = "async_go_proto",
    compilers = ["@io_bazel_rules_go//proto:go_grpc"],
    importpath = "liquid.io/idl/protobufs/gen/async",
    proto = ":async_proto",
    visibility = ["//visibility:public"],
)

go_library(
    name = "libasync",
    embed = [":async_go_proto"],
    importpath = "liquid.io/idl/protobufs/gen/async",
    visibility = ["//visibility:public"],
)
