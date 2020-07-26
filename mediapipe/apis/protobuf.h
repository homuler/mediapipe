#include "common.h"
#include "google/protobuf/stubs/logging.h"

extern "C" {

typedef void LogHandler(int level, const char* filename, int line, const char* message);

MP_CAPI_EXPORT extern google::protobuf::LogHandler* SetProtobufLogHandler(LogHandler* handler);

} // extern "C"
