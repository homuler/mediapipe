#include <string>
#include "mediapipe/apis/framework/port/logging.h"

namespace {
  static const char* argv;
}

void InitGoogleLogging(const char* name, const char* log_dir) {
  std::string text = std::string(name);

  // TODO: caller should manage `name`
  char* tmp = new char[text.size() + 1];
  snprintf(tmp, text.size() + 1, text.c_str());
  argv = tmp;

  FLAGS_log_dir = log_dir;
  google::InitGoogleLogging(argv);
}

void ShutdownGoogleLogging() {
  google::ShutdownGoogleLogging();
  FLAGS_log_dir = "";
  delete argv;
}
