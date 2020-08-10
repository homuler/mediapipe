#ifndef MEDIAPIPE_APIS_GPU_GL_CONTEXT_H_
#define MEDIAPIPE_APIS_GPU_GL_CONTEXT_H_

#include <memory>
#include <utility>
#include "mediapipe/gpu/gl_context.h"
#include "mediapipe/apis/common.h";

extern "C" {

typedef struct MpGlContext {
  std::shared_ptr<mediapipe::GlContext> impl;
} MpGlContext;

MP_CAPI_EXPORT extern MpGlContext* MpGlContextGetCurrent();
MP_CAPI_EXPORT extern MpGlContext* MpGlContextGet();

}  // extern "C"

#endif  // MEDIAPIPE_APIS_GPU_GL_CONTEXT_H_
