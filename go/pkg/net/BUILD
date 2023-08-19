load("@io_bazel_rules_go//go:def.bzl", "go_binary", "go_library", "go_test")

go_library(
    name = "libnet",
    srcs = [
        "conn.go",
        "dial.go",
        "errors.go",
        "tcp_client.go",
        "tcp_server.go",
        "tcp_server_options.go",
        "transport.go",
    ],
    importpath = "liquid.io/go/pkg/net",
    visibility = ["//visibility:public"],
    deps = [
        "//go/pkg/utils",
    ],
)
