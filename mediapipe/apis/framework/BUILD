package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "calculator_graph",
    srcs = ["calculator_graph.cc"],
    hdrs = ["calculator_graph.h"],
    deps = [
        ":packet",
        "//mediapipe/framework:calculator_graph",
        "//mediapipe/framework/port:parse_text_proto",
        "//mediapipe/apis/framework/port:status",
        "//mediapipe/apis/framework/port:statusor",
    ],
    alwayslink = True,
)

cc_library(
    name = "packet",
    srcs = ["packet.cc"],
    hdrs = ["packet.h"],
    deps = [
        "//mediapipe/framework:packet",
    ],
    alwayslink = True,
)
