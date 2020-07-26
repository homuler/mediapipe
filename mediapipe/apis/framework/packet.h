#ifndef MEDIAPIPE_APIS_FRAMEWORK_PACKET_H_
#define MEDIAPIPE_APIS_FRAMEWORK_PACKET_H_

#include <map>
#include <memory>
#include <string>
#include "mediapipe/apis/common.h"
#include "mediapipe/framework/packet.h"

extern "C" {

typedef struct MpPacket {
  std::unique_ptr<mediapipe::Packet> impl;

  MpPacket() : impl { std::make_unique<mediapipe::Packet>() } {}
  MpPacket(mediapipe::Packet&& packet) : impl { std::make_unique<mediapipe::Packet>(packet) } {}
} MpPacket;

typedef struct MpSidePacket {
  std::shared_ptr<std::map<std::string, mediapipe::Packet>> impl;

  MpSidePacket() : impl { std::make_shared<std::map<std::string, mediapipe::Packet>>() } {}
} MpSidePacket;

/** mediapipe::Packet API */
MP_CAPI_EXPORT extern MpPacket* MpPacketCreate();
MP_CAPI_EXPORT extern void MpPacketDestroy(MpPacket* packet);
MP_CAPI_EXPORT extern MpPacket* MpMakeStringPacketAt(const char* str, int timestamp);
MP_CAPI_EXPORT extern const char* MpPacketGetString(MpPacket* packet);

/** SidePacket API */
MP_CAPI_EXPORT extern MpSidePacket* MpSidePacketCreate();
MP_CAPI_EXPORT extern void MpSidePacketDestroy(MpSidePacket* side_packet);
MP_CAPI_EXPORT extern void MpSidePacketInsert(const char* key, MpPacket* packet);

}  // extern "C"

#endif  // MEDIAPIPE_APIS_FRAMEWORK_PACKET_H_
