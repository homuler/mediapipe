#include "mediapipe/framework/port/statusor.h"

typedef void* MpStatusOr;

template <typename T>
bool MpStatusOrOk(MpStatusOr statusor) {
  return static_cast<mediapipe::StatusOr<T>*>(statusor)->ok();
}
