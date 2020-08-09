#ifndef MEDIAPIPE_APIS_GPU_GL_BASE_H_
#define MEDIAPIPE_APIS_GPU_GL_BASE_H_

#include "mediapipe/gpu/gl_base.h"
#include "mediapipe/apis/common.h";

extern "C" {

MP_CAPI_EXPORT extern void GlFlush();
MP_CAPI_EXPORT extern void GlReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum gl_format, GLenum gl_type, uint8_t* pixels);

}  // extern "C"

#endif  // MEDIAPIPE_APIS_GPU_GL_BASE_H_
