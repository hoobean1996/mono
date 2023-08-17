cc_library(
    name = "kv",
    srcs = [
        "db/status.cc",
        "file/file_reader.cc",
        "file/file_writer.cc",
        "table/data_block_builder.cc",
        "wal/wal_writer.cc",
    ],
    hdrs = glob(["**/*.h"]),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "kvcli",
    srcs = ["cli.cc"],
    copts = [],
    deps = [
        "//cc/kv",
        "@com_github_google_glog//:glog",
    ],
)
