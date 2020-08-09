package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "gl_base",
    srcs = ["gl_base.cc"],
    hdrs = ["gl_base.h"],
    deps = [
        "//mediapipe/gpu:gl_base",
        "//mediapipe/apis:common",
    ],
    alwayslink = True,
)

cc_library(
    name = "gpu_shared_data_internal",
    srcs = ["gpu_shared_data_internal.cc"],
    hdrs = ["gpu_shared_data_internal.h"],
    deps = [
        "//mediapipe/gpu:gpu_shared_data_internal",
        "//mediapipe/apis:common",
        "//mediapipe/apis/framework/port:status",
        "//mediapipe/apis/framework/port:statusor",
    ],
    alwayslink = True,
)

cc_library(
    name = "gl_calculator_helper",
    srcs = ["gl_calculator_helper.cc"],
    hdrs = ["gl_calculator_helper.h"],
    deps = [
        ":gpu_shared_data_internal",
        "//mediapipe/gpu:gl_calculator_helper",
        "//mediapipe/apis:common",
        "//mediapipe/apis/framework:packet",
        "//mediapipe/apis/framework/port:statusor",
    ],
    alwayslink = True,
)

cc_library(
    name = "gpu_buffer_format",
    srcs = ["gpu_buffer_format.cc"],
    hdrs = ["gpu_buffer_format.h"],
    deps = [
        "//mediapipe/gpu:gpu_buffer_format",
        "//mediapipe/apis:common",
    ],
    alwayslink = True,
)
