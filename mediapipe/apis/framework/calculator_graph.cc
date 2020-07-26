#include "mediapipe/framework/calculator.pb.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/apis/framework/calculator_graph.h"

MpCalculatorGraphConfig* ParseMpCalculatorGraphConfig(const char* input) {
  auto config = new mediapipe::CalculatorGraphConfig {};
  auto result = google::protobuf::TextFormat::ParseFromString(input, config);

  if (!result) return nullptr;

  return new MpCalculatorGraphConfig { std::unique_ptr<mediapipe::CalculatorGraphConfig> { std::move(config) } };
}

void MpCalculatorGraphConfigDestroy(MpCalculatorGraphConfig* config) {
  delete config;
}

MpCalculatorGraph* MpCalculatorGraphCreate() {
  auto calculator_graph = std::unique_ptr<mediapipe::CalculatorGraph> { new mediapipe::CalculatorGraph() };

  return new MpCalculatorGraph { std::move(calculator_graph) };
}

void MpCalculatorGraphDestroy(MpCalculatorGraph* graph) {
  delete graph;
}

MpStatus* MpCalculatorGraphInitialize(MpCalculatorGraph* graph, MpCalculatorGraphConfig* config) {
  auto status = graph->impl->Initialize(*config->impl);

  return new MpStatus { std::move(status) };
}

MpStatus* MpCalculatorGraphStartRun(MpCalculatorGraph* graph, MpSidePacket* mp_side_packet) {
  auto side_packet = mp_side_packet->impl;
  auto status = graph->impl->StartRun(*side_packet);

  return new MpStatus { std::move(status) };
}

MpStatus* MpCalculatorGraphWaitUntilDone(MpCalculatorGraph* graph) {
  auto status = graph->impl->WaitUntilDone();

  return new MpStatus { std::move(status) };
}

MpStatusOrPoller* MpCalculatorGraphAddOutputStreamPoller(MpCalculatorGraph* graph, const char* name) {
  auto status_or_value = graph->impl->AddOutputStreamPoller(std::string(name));

  return new MpStatusOrPoller { std::move(status_or_value) };
}

bool MpOutputStreamPollerNext(void* mp_poller, MpPacket* packet) {
  auto poller = static_cast<mediapipe::OutputStreamPoller*>(mp_poller);

  return poller->Next(packet->impl.get());
}

MpStatus* MpCalculatorGraphAddStringPacketToInputStream(MpCalculatorGraph* graph, const char* name, const char* value, int timestamp) {
  auto packet = mediapipe::MakePacket<std::string>(std::string(value)).At(mediapipe::Timestamp(timestamp));
  auto status = graph->impl->AddPacketToInputStream(std::string(name), packet);

  return new MpStatus { std::move(status) };
}

MpStatus* MpCalculatorGraphCloseInputStream(MpCalculatorGraph* graph, const char* name) {
  auto status = graph->impl->CloseInputStream(std::string(name));

  return new MpStatus { std::move(status) };
}

bool MpStatusOrPollerOk(MpStatusOrPoller* status_or_poller) {
  return status_or_poller->ok();
}

MpOutputStreamPoller MpStatusOrPollerValue(MpStatusOrPoller* status_or_poller) {
  return status_or_poller->get();
}

void MpStatusOrPollerDestroy(MpStatusOrPoller* status_or_poller) {
  delete status_or_poller;
}
