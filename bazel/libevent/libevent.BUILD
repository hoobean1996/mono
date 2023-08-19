load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "event",
    cache_entries = {
        "EVENT__DISABLE_BENCHMARK": "ON",
        "EVENT__DISABLE_TESTS": "ON",
        "EVENT__DISABLE_SAMPLES": "ON",
        "EVENT__LIBRARY_TYPE": "STATIC",
        "OPENSSL_ROOT_DIR": "$$EXT_BUILD_DEPS$$/openssl",
    },
    generate_args = ["-GNinja"],
    lib_source = ":all_srcs",
    linkopts = [
        "-pthread",
    ],
    out_static_libs = select({
        "@platforms//os:windows": [
            "event.lib",
            "event_core.lib",
            "event_extra.lib",
            "event_openssl.lib",
            "event_pthreads.lib",
        ],
        "//conditions:default": [
            "libevent.a",
            "libevent_core.a",
            "libevent_extra.a",
            "libevent_openssl.a",
            "libevent_pthreads.a",
        ],
    }),
    visibility = ["//visibility:public"],
    deps = [
        # Zlib is only used for testing.
        "@openssl//:crypto",
        "@openssl//:ssl",
    ],
)
