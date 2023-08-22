load("@io_bazel_rules_go//go:def.bzl", "go_binary")

go_binary(
    name = "http_x",
    srcs = ["main.go"],
    deps = [
        "@com_github_gin_gonic_gin//:go_default_library",
        "@com_github_prometheus_client_golang//prometheus:go_default_library",
        "@com_github_prometheus_client_golang//prometheus/promhttp:go_default_library",
        "@com_github_prometheus_client_model//go:go_default_library",
        "@com_github_prometheus_common//expfmt:go_default_library",
    ],
)
