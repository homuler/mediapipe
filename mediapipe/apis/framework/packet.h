#ifdef DLL_EXPORTS
#define MP_CAPI_EXPORT __declspec(dllexport)
#else
#define MP_CAPI_EXPORT
#endif

#include "mediapipe/framework/packet.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* MpPacket;

typedef struct MpSidePacket {
  std::shared_ptr<std::map<std::string, mediapipe::Packet>> impl;
} MpSidePacket;

MP_CAPI_EXPORT extern MpPacket MpPacketCreate();

MP_CAPI_EXPORT extern MpPacket MpMakeStringPacketAt(const char* string, int timestamp);

MP_CAPI_EXPORT extern const char* MpPacketGetString(MpPacket packet);

MP_CAPI_EXPORT extern MpSidePacket* MpSidePacketCreate();

MP_CAPI_EXPORT extern void MpSidePacketInsert(const char* key, MpPacket packet);

#ifdef __cplusplus
} // extern "C"
#endif
