#include "mediapipe/apis/framework/formats/image_frame.h"

MpImageFrame* MpImageFrameCreate(int format_code, int width, int height, int width_step, uint8* pixel_data) {
  auto format = static_cast<mediapipe::ImageFormat::Format>(format_code);

  return new MpImageFrame {
    std::make_unique<mediapipe::ImageFrame>(format, width, height, width_step, pixel_data)
  };
}

void MpImageFrameDestroy(MpImageFrame* image_frame) {
  delete image_frame;
}
