#ifndef MEDIAPIPE_APIS_FRAMEWORK_PORT_STATUSOR_H_
#define MEDIAPIPE_APIS_FRAMEWORK_PORT_STATUSOR_H_

#include <memory>
#include <utility>
#include "mediapipe/framework/port/statusor.h"

template <typename T>
struct MpStatusOrValue {
  std::shared_ptr<mediapipe::Status> status;
  std::unique_ptr<T> value;

  explicit MpStatusOrValue(mediapipe::StatusOr<T>&& status_or) :
    status { std::make_shared<mediapipe::Status>(std::move(status_or.status())) }
  {
    if (status->ok()) {
      value = std::make_unique<T>(status_or.ConsumeValueOrDie());
    }
  }

  explicit MpStatusOrValue(mediapipe::StatusOr<std::unique_ptr<T>>&& status_or) :
    status { std::make_shared<mediapipe::Status>(std::move(status_or.status())) }
  {
    if (status->ok()) {
      value = status_or.ConsumeValueOrDie();
    }
  }
};

#endif  // MEDIAPIPE_APIS_FRAMEWORK_PORT_STATUSOR_H_
