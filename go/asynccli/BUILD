load("@io_bazel_rules_go//go:def.bzl", "go_binary")

go_binary(
    name = "asynccli",
    srcs = ["main.go"],
    deps = [
        "//idl/protobufs/async:libasync",
        "@org_golang_google_grpc//:go_default_library",
    ],
)
