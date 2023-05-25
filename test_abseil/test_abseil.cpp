#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include <iostream>
#include <string>

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

int main() {
  std::string greeting = absl::StrFormat("Hello %s, %d", "Sean", 2023);
  std::cout << greeting << std::endl;

  // abseil flag
  uint16_t port = absl::GetFlag(FLAGS_port);
  std::cout << "port=" << port << std::endl;
  std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
  std::cout << "server_address=" << server_address << std::endl;

  return 0;
}