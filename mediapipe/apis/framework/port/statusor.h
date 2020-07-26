#include "mediapipe/framework/port/statusor.h"

template <typename T>
struct MpStatusOrValue {
  std::shared_ptr<mediapipe::Status> status;
  std::unique_ptr<T> value;

  MpStatusOrValue(mediapipe::StatusOr<T>&& status_or) :
    status { std::shared_ptr<mediapipe::Status> { new mediapipe::Status { std::move(status_or.status()) } } } {
      if (status->ok()) {
        value = std::unique_ptr<T> { new T { std::move(status_or.ValueOrDie()) } };
      }
    }

  ~MpStatusOrValue() {
    if (value) delete value;
  }

  bool ok() const {
    return status->ok();
  }

  T* get() const {
    return this->value.get();
  }
};
