#include <ostream>
#include <fstream>
#include <string>
#include "mediapipe/framework/calculator.pb.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/apis/framework/calculator_graph.h"

MpCalculatorGraphConfig* ParseMpCalculatorGraphConfig(const char* input) {
  auto config = new mediapipe::CalculatorGraphConfig {};
  auto result = google::protobuf::TextFormat::ParseFromString(input, config);

  if (!result) return nullptr;

  return new MpCalculatorGraphConfig { std::unique_ptr<mediapipe::CalculatorGraphConfig> { std::move(config) } };
}

MpCalculatorGraph* MpCalculatorGraphCreate() {
  auto calculator_graph = std::unique_ptr<mediapipe::CalculatorGraph> { new mediapipe::CalculatorGraph() };

  return new MpCalculatorGraph { std::move(calculator_graph) };
}

void MpCalculatorGraphDestroy(MpCalculatorGraph* graph) {
  delete graph;
}

MpStatus MpCalculatorGraphInitialize(MpCalculatorGraph* graph, MpCalculatorGraphConfig* input_config) {
  auto status = graph->impl->Initialize(*input_config->impl);

  return new mediapipe::Status { std::move(status) };
}

MpStatus MpCalculatorGraphStartRun(MpCalculatorGraph* graph, MpSidePacket* mp_side_packet) {
  auto side_packet = mp_side_packet->impl;
  auto status = graph->impl->StartRun(*side_packet);

  return new mediapipe::Status { std::move(status) };
}

MpStatus MpCalculatorGraphWaitUntilDone(MpCalculatorGraph* graph) {
  auto status = graph->impl->WaitUntilDone();

  return new mediapipe::Status { std::move(status) };
}

MpStatusOrPoller MpCalculatorGraphAddOutputStreamPoller(MpCalculatorGraph* graph, const char* name) {
  auto status_or_value = graph->impl->AddOutputStreamPoller(std::string(name));

  return new mediapipe::StatusOrPoller { std::move(status_or_value) };
}

bool MpOutputStreamPollerNext(MpOutputStreamPoller mp_poller, MpPacket mp_packet) {
  auto poller = static_cast<mediapipe::OutputStreamPoller*>(mp_poller);
  auto packet = static_cast<mediapipe::Packet*>(mp_packet);

  return poller->Next(packet);
}

MpStatus MpCalculatorGraphAddStringPacketToInputStream(MpCalculatorGraph* graph, const char* name, const char* value, int timestamp) {
  auto packet = mediapipe::MakePacket<std::string>(std::string(value)).At(mediapipe::Timestamp(timestamp));
  auto status = graph->impl->AddPacketToInputStream(std::string(name), packet);

  return new mediapipe::Status { std::move(status) };
}

MpStatus MpCalculatorGraphCloseInputStream(MpCalculatorGraph* graph, const char* name) {
  auto status = graph->impl->CloseInputStream(std::string(name));

  return new mediapipe::Status { std::move(status) };
}

bool MpStatusOrPollerOk(MpStatusOrPoller _status_or_poller) {
  return MpStatusOrOk<mediapipe::OutputStreamPoller>(_status_or_poller);
}

MpOutputStreamPoller MpStatusOrPollerValueOrDie(MpStatusOrPoller mp_status_or_poller) {
  auto value = std::move(*static_cast<mediapipe::StatusOrPoller*>(mp_status_or_poller)).ValueOrDie();

  return new mediapipe::OutputStreamPoller { std::move(value) };
}
