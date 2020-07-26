#ifdef DLL_EXPORTS
#define MP_CAPI_EXPORT __declspec(dllexport)
#else
#define MP_CAPI_EXPORT
#endif

#include "mediapipe/framework/calculator_graph.h"
#include "mediapipe/apis/framework/packet.h"
#include "mediapipe/apis/framework/port/status.h"
#include "mediapipe/apis/framework/port/statusor.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MpCalculatorGraphConfig {
  std::unique_ptr<mediapipe::CalculatorGraphConfig> impl;
} MpCalculatorGraphConfig;

typedef struct MpCalculatorGraph {
  std::unique_ptr<mediapipe::CalculatorGraph> impl;
} MpCalculatorGraph;

typedef void* MpStatusOrPoller;
typedef void* MpOutputStreamPoller;

MP_CAPI_EXPORT extern MpCalculatorGraphConfig* ParseMpCalculatorGraphConfig(const char* input);

MP_CAPI_EXPORT extern MpCalculatorGraph* MpCalculatorGraphCreate();

MP_CAPI_EXPORT extern void MpCalculatorGraphDestroy(MpCalculatorGraph* graph);

MP_CAPI_EXPORT extern MpStatus MpCalculatorGraphInitialize(MpCalculatorGraph* graph, MpCalculatorGraphConfig* input_config);

MP_CAPI_EXPORT extern MpStatus MpCalculatorGraphStartRun(MpCalculatorGraph* graph, MpSidePacket* side_packet);

MP_CAPI_EXPORT extern MpStatus MpCalculatorGraphWaitUntilDone(MpCalculatorGraph* graph);

MP_CAPI_EXPORT extern MpStatusOrPoller MpCalculatorGraphAddOutputStreamPoller(MpCalculatorGraph* graph, const char* name);

MP_CAPI_EXPORT extern bool MpOutputStreamPollerNext(MpOutputStreamPoller poller, MpPacket packet);

MP_CAPI_EXPORT extern MpStatus MpCalculatorGraphAddStringPacketToInputStream(MpCalculatorGraph* graph, const char* name, const char* packet, int timestamp);

MP_CAPI_EXPORT extern MpStatus MpCalculatorGraphCloseInputStream(MpCalculatorGraph* graph, const char* name);

MP_CAPI_EXPORT extern bool MpStatusOrPollerOk(MpStatusOrPoller status_or_poller);

MP_CAPI_EXPORT extern MpOutputStreamPoller MpStatusOrPollerValueOrDie(MpStatusOrPoller status_or_poller);

#ifdef __cplusplus
} // extern "C"
#endif
