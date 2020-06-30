#include "mediapipe/apis/framework/port/status.h"

bool MpStatusOk(MpStatus status) {
  return static_cast<mediapipe::Status*>(status)->ok();
}

int GetMpStatusRawCode(MpStatus status) {
  return static_cast<mediapipe::Status*>(status)->raw_code();
}

const char* MpStatusToString(MpStatus status) {
  auto text = static_cast<mediapipe::Status*>(status)->ToString();

  char* result = new char[text.size()];
  strcpy(result, text.c_str());

  return result;
}
