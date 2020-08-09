#ifndef MEDIAPIPE_APIS_FRAMEWORK_PORT_STATUS_H_
#define MEDIAPIPE_APIS_FRAMEWORK_PORT_STATUS_H_

#include <memory>
#include <utility>
#include "mediapipe/framework/port/status.h"
#include "mediapipe/apis/common.h";

extern "C" {

typedef struct MpStatus {
  std::shared_ptr<mediapipe::Status> impl;

  MpStatus(mediapipe::Status status) : impl { std::make_shared<mediapipe::Status>(std::move(status)) } {}
} MpStatus;

MP_CAPI_EXPORT extern MpStatus* MpStatusCreate(int code, const char* message);
MP_CAPI_EXPORT extern void MpStatusDestroy(MpStatus* status);
MP_CAPI_EXPORT extern bool MpStatusOk(MpStatus* status);
MP_CAPI_EXPORT extern int GetMpStatusRawCode(MpStatus* status);
MP_CAPI_EXPORT extern const char* MpStatusToString(MpStatus* status);

}  // extern "C"

#endif  // MEDIAPIPE_APIS_FRAMEWORK_PORT_STATUS_H_
