#include "mediapipe/apis/framework/formats/image_frame.h"

mediapipe::ImageFrame* MpImageFrameCreate(int format_code, int width, int height, int width_step, uint8* pixel_data) {
  auto format = static_cast<mediapipe::ImageFormat::Format>(format_code);

  return new mediapipe::ImageFrame { format, width, height, width_step, pixel_data };
}

bool MpImageFrameIsEmpty(mediapipe::ImageFrame* image_frame) {
  return image_frame->IsEmpty();
}

int MpImageFrameWidth(mediapipe::ImageFrame* image_frame) {
  return image_frame->Width();
}

int MpImageFrameHeight(mediapipe::ImageFrame* image_frame) {
  return image_frame->Height();
}

int MpImageFrameChannelSize(mediapipe::ImageFrame* image_frame) {
  return image_frame->ChannelSize();
}

int MpImageFrameNumberOfChannels(mediapipe::ImageFrame* image_frame) {
  return image_frame->NumberOfChannels();
}

int MpImageFrameByteDepth(mediapipe::ImageFrame* image_frame) {
  return image_frame->ByteDepth();
}

int MpImageFrameWidthStep(mediapipe::ImageFrame* image_frame) {
  return image_frame->WidthStep();
}

const uint8* MpImageFramePixelData(mediapipe::ImageFrame* image_frame) {
  return image_frame->PixelData();
}

void MpStatusOrImageFrameDestroy(MpStatusOrImageFrame* status_or_image_frame) {
  delete status_or_image_frame;
}

mediapipe::ImageFrame* MpStatusOrImageFrameValue(MpStatusOrImageFrame* status_or_image_frame) {
  return status_or_image_frame->value.get();
}
