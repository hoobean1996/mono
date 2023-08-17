cc_library(
    name = "coro_task",
    srcs = [
        "detached_task.cc",
        "detached_task_handle.cc",
        "task.cc",
    ],
    hdrs = [
        "detached_task.h",
        "detached_task_handle.cc",
        "task.h",
    ],
    visibility = ["//visibility:public"],
    deps = [],
)

cc_test(
    name = "coro_task_test",
    size = "small",
    srcs = ["task_test.cc"],
    deps = [
        "//cc/coro:coro_task",
        "@com_google_googletest//:gtest_main",
    ],
)
