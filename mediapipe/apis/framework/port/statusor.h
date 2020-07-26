#include "mediapipe/framework/port/statusor.h"

template <typename T>
struct MpStatusOrValue {
  std::shared_ptr<mediapipe::Status> status;
  std::unique_ptr<T> value;

  MpStatusOrValue(mediapipe::StatusOr<T>&& status_or) :
    status { std::make_shared<mediapipe::Status>(std::move(status_or.status())) }
  {
    if (status->ok()) {
      value = std::make_unique<T>(std::move(status_or.ValueOrDie()));
    }
  }

  bool ok() const {
    return status->ok();
  }

  T* get() const {
    return this->value.get();
  }
};
