# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "cetty",
    srcs = [
        "acceptor.cc",
        "addr.cc",
        "buffer.cc",
        "channel.cc",
        "client.cc",
        "connection.cc",
        "event_loop.cc",
        "poller.cc",
        "server.cc",
        "tcp_server.cc",
    ],
    hdrs = [
        "acceptor.h",
        "addr.h",
        "buffer.h",
        "channel.h",
        "client.h",
        "connection.h",
        "event_handler.h",
        "event_loop.h",
        "poller.h",
        "server.h",
        "tcp_server.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_google_glog//:glog",
    ],
)
