#include <functional>
#include "mediapipe/apis/protobuf.h"

using google::protobuf::LogLevel;

namespace {
  LogHandler* logHandler;
}

void HandleProtobufLog(LogLevel level, const char* filename, int line, const std::string& message) {
  logHandler(level, filename, line, message.c_str());
};

google::protobuf::LogHandler* SetProtobufLogHandler(LogHandler* lh) {
  logHandler = lh;

  return google::protobuf::SetLogHandler(&HandleProtobufLog);
}
