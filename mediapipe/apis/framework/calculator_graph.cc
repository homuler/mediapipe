#include <ostream>
#include <fstream>
#include <string>
#include "mediapipe/framework/calculator.pb.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/apis/framework/calculator_graph.h"

void debug(std::string text) {
  std::ofstream file;

  file.open("log.txt", std::ios_base::app);
  file << text << "\n";
  file.close();
}

MpCalculatorGraphConfig ParseMpCalculatorGraphConfigOrDie(const char* input) {
  auto config = mediapipe::ParseTextProtoOrDie<mediapipe::CalculatorGraphConfig>(input);

  return new mediapipe::CalculatorGraphConfig { std::move(config) };
}

MpCalculatorGraph MpCalculatorGraphCreate() {
  return new mediapipe::CalculatorGraph();
}

void MpCalculatorGraphDestroy(MpCalculatorGraph graph) {
  delete graph;
}

MpStatus MpCalculatorGraphInitialize(MpCalculatorGraph graph, MpCalculatorGraphConfig input_config) {
  auto calculator_graph = static_cast<mediapipe::CalculatorGraph*>(graph);
  auto graph_config = static_cast<mediapipe::CalculatorGraphConfig*>(input_config);
  auto status = calculator_graph->Initialize(*graph_config);

  return new mediapipe::Status { std::move(status) };
}

MpStatus MpCalculatorGraphStartRun(MpCalculatorGraph mp_graph, MpSidePacket* mp_side_packet) {
  auto graph = static_cast<mediapipe::CalculatorGraph*>(mp_graph);
  auto side_packet = mp_side_packet->impl;
  auto status = graph->StartRun(*side_packet);

  return new mediapipe::Status { std::move(status) };
}

MpStatus MpCalculatorGraphWaitUntilDone(MpCalculatorGraph mp_calculator_graph) {
  auto graph = static_cast<mediapipe::CalculatorGraph*>(mp_calculator_graph);
  auto status = graph->WaitUntilDone();

  return new mediapipe::Status { std::move(status) };
}

MpStatusOrPoller MpCalculatorGraphAddOutputStreamPoller(MpCalculatorGraph graph, const char* name) {
  auto calculator_graph = static_cast<mediapipe::CalculatorGraph*>(graph);
  auto status_or_value = calculator_graph->AddOutputStreamPoller(std::string(name));

  return new mediapipe::StatusOrPoller { std::move(status_or_value) };
}

bool MpOutputStreamPollerNext(MpOutputStreamPoller mp_poller, MpPacket mp_packet) {
  auto poller = static_cast<mediapipe::OutputStreamPoller*>(mp_poller);
  auto packet = static_cast<mediapipe::Packet*>(mp_packet);

  return poller->Next(packet);
}

MpStatus MpCalculatorGraphAddStringPacketToInputStream(MpCalculatorGraph graph, const char* name, const char* value, int timestamp) {
  auto calculator_graph = static_cast<mediapipe::CalculatorGraph*>(graph);
  auto packet = mediapipe::MakePacket<std::string>(std::string(value)).At(mediapipe::Timestamp(timestamp));
  auto status = calculator_graph->AddPacketToInputStream(std::string(name), packet);

  return new mediapipe::Status { std::move(status) };
}

MpStatus MpCalculatorGraphCloseInputStream(MpCalculatorGraph graph, const char* name) {
  auto calculator_graph = static_cast<mediapipe::CalculatorGraph*>(graph);
  auto status = calculator_graph->CloseInputStream(std::string(name));

  return new mediapipe::Status { std::move(status) };
}

bool MpStatusOrPollerOk(MpStatusOrPoller _status_or_poller) {
  return MpStatusOrOk<mediapipe::OutputStreamPoller>(_status_or_poller);
}

MpOutputStreamPoller MpStatusOrPollerValueOrDie(MpStatusOrPoller mp_status_or_poller) {
  auto value = std::move(*static_cast<mediapipe::StatusOrPoller*>(mp_status_or_poller)).ValueOrDie();

  return new mediapipe::OutputStreamPoller { std::move(value) };
}
