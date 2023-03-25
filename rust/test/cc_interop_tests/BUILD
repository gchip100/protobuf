# This package contains tests exercising C++/Rust interop, for example mutating a Rust proto in C++.

load("@rules_rust//rust:defs.bzl", "rust_test")

cc_library(
    name = "uses_unittest_proto",
    srcs = ["uses_unittest_proto.cc"],
    deps = [
        "//third_party/protobuf:unittest_cc_proto",
        "//rust/cpp_kernel:cpp_thunks_api",
    ],
)

rust_test(
    name = "cpp_rust_interop_tests",
    srcs = ["cpp_rust_interop_tests.rs"],
    tags = [
        # TODO(b/270274576): Enable testing on arm once we have a Rust Arm toolchain.
        "not_build:arm",
        # TODO(b/243126140): Enable tsan once we support sanitizers with Rust.
        "notsan",
        # TODO(b/243126140): Enable msan once we support sanitizers with Rust.
        "nomsan",
    ],
    deps = [
        ":uses_unittest_proto",
        "//rust:protobuf",
        "//rust/test:unittest_rust_proto",
    ],
)
