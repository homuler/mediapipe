#include "mediapipe/apis/gpu/gpu_buffer_format.h"

int MpImageFormatForGpuBufferFormat(uint32_t gpu_format_code) {
  auto gpu_format { static_cast<mediapipe::GpuBufferFormat>(gpu_format_code) };

  return mediapipe::ImageFormatForGpuBufferFormat(gpu_format);
}

mediapipe::GlTextureInfo* MpGlTextureInfoGpuBufferFormat(uint32_t gpu_format_code, int plane) {
  auto gpu_format { static_cast<mediapipe::GpuBufferFormat>(gpu_format_code) };

  return new mediapipe::GlTextureInfo { mediapipe::GlTextureInfoForGpuBufferFormat(gpu_format, plane) };
}
