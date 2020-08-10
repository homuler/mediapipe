cc_binary(
    name = "mediapipe_c",
    deps = [
        ":calculators",
        ":protobuf",
        "//mediapipe/apis/framework:calculator_graph",
        "//mediapipe/apis/framework/port:logging",
    ] + select({
        "//mediapipe/gpu:disable_gpu": [],
        "//conditions:default": [
            "//mediapipe/apis/gpu:gl_base",
            "//mediapipe/apis/gpu:gl_context",
            "//mediapipe/apis/gpu:gl_calculator_helper",
            "//mediapipe/apis/gpu:gpu_buffer_format",
            "//mediapipe/apis/gpu:gpu_shared_data_internal",
        ],
    }),
    visibility = None,
    linkshared = True,
)

# It is recommended that you include only neccessary calculators.
cc_library(
    name = "calculators",
    deps = [
        "//mediapipe/calculators/core:pass_through_calculator",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/image:image_transformation_calculator",
        "//mediapipe/calculators/tflite:ssd_anchors_calculator",
        "//mediapipe/calculators/tflite:tflite_converter_calculator",
        "//mediapipe/calculators/tflite:tflite_inference_calculator",
        "//mediapipe/calculators/tflite:tflite_tensors_to_detections_calculator",
        "//mediapipe/calculators/util:annotation_overlay_calculator",
        "//mediapipe/calculators/util:detection_label_id_to_text_calculator",
        "//mediapipe/calculators/util:detection_letterbox_removal_calculator",
        "//mediapipe/calculators/util:detections_to_render_data_calculator",
        "//mediapipe/calculators/util:non_max_suppression_calculator",
    ] + select({
        "//mediapipe/gpu:disable_gpu": [],
        "//conditions:default": [
            "//mediapipe/gpu:gpu_buffer_to_image_frame_calculator",
            "//mediapipe/gpu:image_frame_to_gpu_buffer_calculator",
        ],
    }),
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
