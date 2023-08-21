load("@io_bazel_rules_go//go:def.bzl", "go_library")

go_library(
    name = "librpc",
    srcs = [
        "client.go",
        "client_options.go",
        "codec.go",
        "compress.go",
        "service.go",
    ],
    importpath = "liquid.io/go/pkg/rpc",
    visibility = ["//visibility:public"],
    deps = [
        "//go/pkg/net:libnet",
    ],
)
