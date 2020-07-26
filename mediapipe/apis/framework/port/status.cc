#include "mediapipe/apis/framework/port/status.h"

void MpStatusDestroy(MpStatus* status) {
  delete status;
}

bool MpStatusOk(MpStatus* status) {
  return status->impl->ok();
}

int GetMpStatusRawCode(MpStatus* status) {
  return status->impl->raw_code();
}

const char* MpStatusToString(MpStatus* status) {
  auto text = status->impl->ToString();

  char* result = new char[text.size() + 1];
  snprintf(result, text.size() + 1, text.c_str());

  return result;
}
