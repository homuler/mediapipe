#include "mediapipe/apis/framework/port/status.h"

bool MpStatusOk(MpStatus* status) {
  return status->impl->ok();
}

int GetMpStatusRawCode(MpStatus* status) {
  return status->impl->raw_code();
}

const char* MpStatusToString(MpStatus* status) {
  auto text = status->impl->ToString();

  char* result = new char[text.size()];
  strcpy(result, text.c_str());

  return result;
}
