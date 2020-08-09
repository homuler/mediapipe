#include <utility>
#include "mediapipe/apis/gpu/gl_calculator_helper.h"

MpGlCalculatorHelper* MpGlCalculatorHelperCreate() {
  return new MpGlCalculatorHelper();
}

void MpGlCalculatorHelperDestroy(MpGlCalculatorHelper* gpu_helper) {
  delete gpu_helper;
}

void MpGlCalculatorHelperInitializeForTest(MpGlCalculatorHelper* gpu_helper, MpGpuResources* gpu_resources) {
  gpu_helper->impl->InitializeForTest(gpu_resources->impl.get());
}

MpStatus* MpGlCalculatorHelperRunInGlContext(MpGlCalculatorHelper* gpu_helper, MpGlStatusFunction* gl_func) {
  auto status = gpu_helper->impl->RunInGlContext([&gl_func]() -> ::mediapipe::Status {
    auto mp_status { (*gl_func)() };

    return *mp_status->impl.get();
  });

  return new MpStatus { std::move(status) };
}

mediapipe::GlTexture* MpGlCalculatorHelperCreateSourceTexture(MpGlCalculatorHelper* gpu_helper, mediapipe::ImageFrame* image_frame) {
  return new mediapipe::GlTexture { gpu_helper->impl->CreateSourceTexture(*image_frame) };
}

void MpGlCalculatorHelperBindFramebuffer(MpGlCalculatorHelper* gpu_helper, mediapipe::GlTexture* gl_texture) {
  gpu_helper->impl->BindFramebuffer(*gl_texture);
}

void MpGlTextureRelease(mediapipe::GlTexture* gl_texture) {
  gl_texture->Release();
}

void MpGpuBufferDestroy(MpGpuBuffer* gpu_buffer) {
  delete gpu_buffer;
}

uint32_t MpGpuBufferFormat(MpGpuBuffer* gpu_buffer) {
  return static_cast<uint32_t>(gpu_buffer->impl->format());
}

int MpGpuBufferWidth(MpGpuBuffer* gpu_buffer) {
  return gpu_buffer->impl->width();
}

int MpGpuBufferHeight(MpGpuBuffer* gpu_buffer) {
  return gpu_buffer->impl->height();
}

MpGpuBuffer* MpGlTextureGetGpuBufferFrame(mediapipe::GlTexture* gl_texture) {
  auto gpu_frame = gl_texture->GetFrame<mediapipe::GpuBuffer>();

  return new MpGpuBuffer { std::move(gpu_frame) };
}

MpPacket* MpMakeGpuBufferPacketAt(MpGpuBuffer* gpu_buffer, int timestamp) {
  auto packet = mediapipe::Adopt(gpu_buffer->impl.get()).At(mediapipe::Timestamp(timestamp));

  return new MpPacket { std::move(packet) };
}

MpStatusOrGpuBuffer* MpPacketConsumeGpuBuffer(MpPacket* packet) {
  auto status_or_gpu_buffer = packet->impl->Consume<mediapipe::GpuBuffer>();

  return new MpStatusOrGpuBuffer { std::move(status_or_gpu_buffer) };
}

MpGpuBuffer* MpStatusOrGpuBufferConsumeValue(MpStatusOrGpuBuffer* gpu_buffer) {
  return new MpGpuBuffer { std::move(gpu_buffer->value) };
}
