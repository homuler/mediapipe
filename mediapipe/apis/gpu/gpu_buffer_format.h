#ifndef MEDIAPIPE_APIS_GPU_GPU_BUFFER_FORMAT_H_
#define MEDIAPIPE_APIS_GPU_GPU_BUFFER_FORMAT_H_

#include "mediapipe/gpu/gpu_buffer_format.h"
#include "mediapipe/apis/common.h";

extern "C" {

MP_CAPI_EXPORT extern int MpImageFormatForGpuBufferFormat(uint32_t gpu_format_code);
MP_CAPI_EXPORT extern mediapipe::GlTextureInfo* MpGlTextureInfoGpuBufferFormat(uint32_t gpu_format_code, int plane);

}  // extern "C"

#endif  // MEDIAPIPE_APIS_GPU_GPU_BUFFER_FORMAT_H_
