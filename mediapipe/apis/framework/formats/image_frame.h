#ifndef MEDIAPIPE_APIS_FRAMEWORK_FORMATS_IMAGE_FRAME_H_
#define MEDIAPIPE_APIS_FRAMEWORK_FORMATS_IMAGE_FRAME_H_

#include <memory>
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/apis/common.h";

extern "C" {

typedef struct MpImageFrame {
  std::unique_ptr<mediapipe::ImageFrame> impl;
} MpImageFrame;

MP_CAPI_EXPORT extern MpImageFrame* MpImageFrameCreate(int format_code, int width, int height, int width_step, uint8* pixel_data);
MP_CAPI_EXPORT extern void MpImageFrameDestroy(MpImageFrame* image_frame);

}  // extern "C"

#endif  // MEDIAPIPE_APIS_FRAMEWORK_FORMATS_IMAGE_FRAME_H_
