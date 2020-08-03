#include <string>
#include <utility>
#include "mediapipe/apis/framework/packet.h"

MpPacket* MpPacketCreate() {
  return new MpPacket();
}

void MpPacketDestroy(MpPacket* packet) {
  delete packet;
}

MpPacket* MpMakeStringPacketAt(const char* string, int timestamp) {
  auto packet = mediapipe::MakePacket<std::string>(std::string(string)).At(mediapipe::Timestamp(timestamp));

  return new MpPacket { std::move(packet) };
}

const char* MpPacketGetString(MpPacket* packet) {
  auto text = packet->impl->Get<std::string>();

  char* result = new char[text.size() + 1];
  snprintf(result, text.size() + 1, text.c_str());

  return result;
}

MpPacket* MpMakeImageFramePacketAt(mediapipe::ImageFrame* image_frame, int timestamp) {
  auto packet = mediapipe::Adopt(image_frame).At(mediapipe::Timestamp(timestamp));

  return new MpPacket { std::move(packet) };
}

MpStatusOrImageFrame* MpPacketConsumeImageFrame(MpPacket* packet) {
  auto status_or_image_frame = packet->impl->Consume<mediapipe::ImageFrame>();

  return new MpStatusOrImageFrame { std::move(status_or_image_frame) };
}

MpSidePacket* MpSidePacketCreate() {
  return new MpSidePacket();
}

void MpSidePacketDestroy(MpSidePacket* side_packet) {
  delete side_packet;
}

void MpSidePacketInsert(MpSidePacket* side_packet, const char* key, MpPacket* packet) {
  side_packet->impl->emplace(std::string(key), *packet->impl.get());
}
