#include <string>
#include "mediapipe/apis/framework/packet.h"

MpPacket MpPacketCreate() {
  return new mediapipe::Packet {};
}

MpPacket MpMakeStringPacketAt(const char* string, int timestamp) {
  auto packet = mediapipe::MakePacket<std::string>(std::string(string)).At(mediapipe::Timestamp(timestamp));

  return std::move(&packet);
}

const char* MpPacketGetString(MpPacket mp_packet) {
  auto packet = static_cast<mediapipe::Packet*>(mp_packet);
  auto text = packet->Get<std::string>();

  char* result = new char[text.size()];
  strcpy(result, text.c_str());

  return result;
}

MpSidePacket* MpSidePacketCreate() {
  auto map = std::make_shared<std::map<std::string, mediapipe::Packet>>();

  return new MpSidePacket { map };
}

void MpSidePacketInsert(MpSidePacket* mp_side_packet, const char* key, MpPacket mp_packet) {
  auto packet = static_cast<mediapipe::Packet*>(mp_packet);
  std::pair<std::string, mediapipe::Packet> pair(std::string(key), *packet);

  mp_side_packet->impl->emplace(std::string(key), *packet);
}
