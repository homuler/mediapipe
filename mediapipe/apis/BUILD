cc_binary(
    name = "mediapipe_c",
    deps = [
        "//mediapipe/calculators/core:pass_through_calculator",
        "//mediapipe/apis/framework:calculator_graph",
        "//mediapipe/apis/framework/formats:image_frame",
        ":protobuf",
    ],
    visibility = None,
    linkshared = True,
)

cc_library(
    name = "common",
    hdrs = ["common.h"],
    alwayslink = True,
    visibility = ["//visibility:public"],
)

cc_library(
    name = "protobuf",
    srcs = ["protobuf.cc"],
    hdrs = ["protobuf.h"],
    deps = [
        "@com_google_protobuf//:protobuf",
        ":common",
    ],
    alwayslink = True,
)

cc_binary(
    name = "runner",
    srcs = ["runner.cc"],
    visibility = None,
    deps = [
        "//mediapipe/calculators/core:pass_through_calculator",
        "//mediapipe/apis/framework:calculator_graph",
    ],
)
