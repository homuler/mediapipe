package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "status",
    srcs = ["status.cc"],
    hdrs = ["status.h"],
    deps = [
        "//mediapipe/apis:common",
        "//mediapipe/framework/port:status",
    ],
    alwayslink = True,
)

cc_library(
    name = "statusor",
    hdrs = ["statusor.h"],
    deps = [
        "//mediapipe/apis:common",
        "//mediapipe/framework/port:statusor",
    ],
    alwayslink = True,
)
