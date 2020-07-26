#include "mediapipe/framework/port/status.h"
#include "mediapipe/apis/common.h";

extern "C" {

typedef struct MpStatus {
  std::shared_ptr<mediapipe::Status> impl;

  MpStatus(mediapipe::Status&& status) : impl { std::shared_ptr<mediapipe::Status> { new mediapipe::Status { status } } } {}
} MpStatus;

MP_CAPI_EXPORT extern bool MpStatusOk(MpStatus* status);

MP_CAPI_EXPORT extern int GetMpStatusRawCode(MpStatus* status);

MP_CAPI_EXPORT extern const char* MpStatusToString(MpStatus* status);

} // extern "C"
