load("@io_bazel_rules_go//go:def.bzl", "go_binary")

go_binary(
    name = "asyncd",
    srcs = ["main.go"],
    deps = [
        "//idl/protobufs/async:libasync",
        "@com_github_prometheus_client_golang//prometheus:go_default_library",
        "@com_github_prometheus_client_golang//prometheus/promhttp:go_default_library",
        "@com_github_prometheus_client_model//go:go_default_library",
        "@com_github_prometheus_common//expfmt:go_default_library",
        "@org_golang_google_grpc//:go_default_library",
    ],
)
