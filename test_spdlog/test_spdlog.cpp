// #include "spdlog/fmt/bundled/format.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/null_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/spdlog.h"
#include <atomic>
#include <cstdlib> // EXIT_FAILURE
#include <iostream>
#include <memory>
#include <string>
#include <thread>

void bench(int howmany, std::shared_ptr<spdlog::logger> log);
void bench_mt(int howmany, std::shared_ptr<spdlog::logger> log,
              size_t thread_count);

#include <iomanip>
#include <locale>
#include <sstream>

namespace utils {

template <typename T> inline std::string format(const T &value) {
  static std::locale loc("");
  std::stringstream ss;
  ss.imbue(loc);
  ss << value;
  return ss.str();
}

template <> inline std::string format(const double &value) {
  static std::locale loc("");
  std::stringstream ss;
  ss.imbue(loc);
  ss << std::fixed << std::setprecision(1) << value;
  return ss.str();
}

} // namespace utils

void basic_logfile_example() {
  try {
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }
}

void rotating_example() {
  // Create a file rotating logger with 5 MB size max and 3 rotated files
  auto max_size = 1048576 * 5;
  auto max_files = 3;
  auto logger = spdlog::rotating_logger_mt(
      "some_logger_name", "logs/rotating.txt", max_size, max_files);
  logger->info("rotating_example");
}

void daily_example() {
  // Create a daily logger - a new file is created every day at 2:30 am
  auto logger =
      spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
}

void backtrace_example() {
  // Debug messages can be stored in a ring buffer instead of being logged
  // immediately.
  // This is useful to display debug logs only when needed (e.g. when an error
  // happens). When needed, call dump_backtrace() to dump them to your log.

  spdlog::enable_backtrace(32); // Store the latest 32 messages in a buffer.
  // or my_logger->enable_backtrace(32)..
  for (int i = 0; i < 100; i++) {
    spdlog::debug("Backtrace message {}", i); // not logged yet..
  }
  // e.g. if some error happened:
  spdlog::dump_backtrace(); // log them now! show the last 32 messages
  // or my_logger->dump_backtrace(32)..
}

void replace_default_logger_example() {
  auto new_logger = spdlog::basic_logger_mt("new_default_logger",
                                            "logs/new-default-log.txt", true);
  spdlog::set_default_logger(new_logger);
  spdlog::info("new logger log message");
}

int main() {
  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);

  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical(
      "Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");

  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  spdlog::debug("This message should be displayed..");

  // change log pattern
  spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
  // spdlog::info("Welcome to spdlog!");

  // Compile time log levels
  // define SPDLOG_ACTIVE_LEVEL to desired level
  SPDLOG_TRACE("Some trace message with param {}", 42);
  SPDLOG_DEBUG("Some debug message");
}

// void bench_mt(int howmany, std::shared_ptr<spdlog::logger> log,
//               size_t thread_count) {
//   using std::chrono::duration;
//   using std::chrono::duration_cast;
//   using std::chrono::high_resolution_clock;

//   std::vector<std::thread> threads;
//   threads.reserve(thread_count);
//   auto start = high_resolution_clock::now();
//   for (size_t t = 0; t < thread_count; ++t) {
//     threads.emplace_back([&]() {
//       for (int j = 0; j < howmany / static_cast<int>(thread_count); j++) {
//         log->info("Hello logger: msg number {}", j);
//       }
//     });
//   }

//   for (auto &t : threads) {
//     t.join();
//   };

//   auto delta = high_resolution_clock::now() - start;
//   auto delta_d = duration_cast<duration<double>>(delta).count();
//   spdlog::info(spdlog::fmt_lib::format(
//       std::locale("en_US.UTF-8"), "{:<30} Elapsed: {:0.2f} secs {:>16L}/sec",
//       log->name(), delta_d, int(howmany / delta_d)));
//   spdlog::drop(log->name());
// }

// void bench_mt(int howmany, std::shared_ptr<spdlog::logger> log,
//               size_t thread_count) {
//   using std::chrono::duration;
//   using std::chrono::duration_cast;
//   using std::chrono::high_resolution_clock;

//   std::vector<std::thread> threads;
//   threads.reserve(thread_count);
//   auto start = high_resolution_clock::now();
//   for (size_t t = 0; t < thread_count; ++t) {
//     threads.emplace_back([&]() {
//       for (int j = 0; j < howmany / static_cast<int>(thread_count); j++) {
//         log->info("Hello logger: msg number {}", j);
//       }
//     });
//   }

//   for (auto &t : threads) {
//     t.join();
//   };

//   auto delta = high_resolution_clock::now() - start;
//   auto delta_d = duration_cast<duration<double>>(delta).count();
//   spdlog::info(spdlog::fmt_lib::format(
//       std::locale("en_US.UTF-8"), "{:<30} Elapsed: {:0.2f} secs {:>16L}/sec",
//       log->name(), delta_d, int(howmany / delta_d)));
//   spdlog::drop(log->name());
// }
