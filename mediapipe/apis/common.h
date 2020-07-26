#ifndef MEDIAPIPE_APIS_COMMON_H_
#define MEDIAPIPE_APIS_COMMON_H_

#ifdef DLL_EXPORTS
#define MP_CAPI_EXPORT __declspec(dllexport)
#else
#define MP_CAPI_EXPORT
#endif

#endif  // MEDIAPIPE_APIS_COMMON_H_
