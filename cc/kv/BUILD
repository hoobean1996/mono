cc_library(
    name = "libkv",
    srcs = glob([
        "*.cc",
    ]),
    hdrs = glob([
        "*.h",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_google_glog//:glog",
    ],
)

cc_binary(
    name = "kvcli",
    srcs = ["bin/cli.cc"],
    copts = [],
    deps = [
        "//cc/kv:libkv",
        "@com_github_gflags_gflags//:gflags",
        # "@com_github_google_glog//:glog",
    ],
)
