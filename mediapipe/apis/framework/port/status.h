#ifdef DLL_EXPORTS
#define MP_CAPI_EXPORT __declspec(dllexport)
#else
#define MP_CAPI_EXPORT
#endif

#include "mediapipe/framework/port/status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* MpStatus;

MP_CAPI_EXPORT extern bool MpStatusOk(MpStatus status);

MP_CAPI_EXPORT extern int GetMpStatusRawCode(MpStatus status);

MP_CAPI_EXPORT extern const char* MpStatusToString(MpStatus status);


#ifdef __cplusplus
} // extern "C"
#endif
