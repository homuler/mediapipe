#ifndef MEDIAPIPE_APIS_FRAMEWORK_FORMATS_IMAGE_FRAME_H_
#define MEDIAPIPE_APIS_FRAMEWORK_FORMATS_IMAGE_FRAME_H_

#include <memory>
#include <utility>
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/apis/common.h";
#include "mediapipe/apis/framework/port/status.h";
#include "mediapipe/apis/framework/port/statusor.h";

extern "C" {

typedef MpStatusOrValue<std::unique_ptr<mediapipe::ImageFrame>> MpStatusOrImageFrame;
typedef void (*Deleter)(uint8*);

MP_CAPI_EXPORT extern mediapipe::ImageFrame* MpImageFrameCreate(
    int format_code, int width, int height, uint32 alignment_boundary);
MP_CAPI_EXPORT extern mediapipe::ImageFrame* MpImageFrameCreateDefault();
MP_CAPI_EXPORT extern mediapipe::ImageFrame* MpImageFrameCreateWithPixelData(
    int format_code, int width, int height, int width_step, uint8* pixel_data, Deleter deleter);
MP_CAPI_EXPORT extern void MpImageFrameDestroy(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern bool MpImageFrameIsEmpty(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern int MpImageFrameFormat(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern int MpImageFrameWidth(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern int MpImageFrameHeight(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern int MpImageFrameChannelSize(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern int MpImageFrameNumberOfChannels(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern int MpImageFrameByteDepth(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern int MpImageFrameWidthStep(mediapipe::ImageFrame* image_frame);
MP_CAPI_EXPORT extern uint8* MpImageFramePixelData(mediapipe::ImageFrame* image_frame);

MP_CAPI_EXPORT extern void MpStatusOrImageFrameDestroy(MpStatusOrImageFrame* image_frame);
MP_CAPI_EXPORT extern MpStatus* MpStatusOrImageFrameStatus(MpStatusOrImageFrame* image_frame);
MP_CAPI_EXPORT extern mediapipe::ImageFrame* MpStatusOrImageFrameConsumeValue(MpStatusOrImageFrame* image_frame);

}  // extern "C"

#endif  // MEDIAPIPE_APIS_FRAMEWORK_FORMATS_IMAGE_FRAME_H_
