#ifndef MEDIAPIPE_APIS_FRAMEWORK_PORT_LOGGING_H_
#define MEDIAPIPE_APIS_FRAMEWORK_PORT_LOGGING_H_

#include "mediapipe/framework/port/logging.h"
#include "mediapipe/apis/common.h";

extern "C" {

MP_CAPI_EXPORT extern void InitGoogleLogging(const char* name, const char* log_dir);
MP_CAPI_EXPORT extern void ShutdownGoogleLogging();

}  // extern "C"

#endif  // MEDIAPIPE_APIS_FRAMEWORK_PORT_LOGGING_H_
