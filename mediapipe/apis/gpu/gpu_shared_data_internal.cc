#include "mediapipe/apis/gpu/gpu_shared_data_internal.h"

void MpGpuResourcesDestroy(MpGpuResources* gpu_resources) {
  delete gpu_resources;
}

mediapipe::GpuResources* MpGpuResourcesGet(MpGpuResources* gpu_resources) {
  return gpu_resources->impl.get();
}

MpStatusOrGpuResources* MpGpuResourcesCreate() {
  auto status_or_gpu_resources = mediapipe::GpuResources::Create();
  auto status = status_or_gpu_resources.status();
  auto gpu_resources = status.ok() ? new MpGpuResources { status_or_gpu_resources.ConsumeValueOrDie() } : nullptr;

  return new MpStatusOrGpuResources { status, std::unique_ptr<MpGpuResources>(gpu_resources) };
}

void MpStatusOrGpuResourcesDestroy(MpStatusOrGpuResources* gpu_resources) {
  delete gpu_resources;
}

MpStatus* MpStatusOrGpuResourcesStatus(MpStatusOrGpuResources* gpu_resources) {
  return new MpStatus { *gpu_resources->status };
}

MpGpuResources* MpStatusOrGpuResourcesConsumeValue(MpStatusOrGpuResources* gpu_resources) {
  return gpu_resources->value.release();
}
