#include "quill/Quill.h"

int main()
{
  // formatter
  quill::Handler* file_handler = quill::stdout_handler();
  file_handler->set_pattern(
    //QUILL_STRING("%(ascii_time) [%(process)] [%(thread)] %(logger_name) - %(message)"), // format
    QUILL_STRING("%(ascii_time) [%(level_id)] [%(filename)] [%(lineno)] [%(function_name)] %(message)"), // format
    //"%D %H:%M:%S.%Qms %z",     // timestamp format
    "%D %H:%M:%S.%Qms %z",     // timestamp format
    //quill::Timezone::GmtTime); // timestamp's timezone
    quill::Timezone::LocalTime); // timestamp's timezone

  quill::set_default_logger_handler(file_handler);


  quill::enable_console_colours();
  quill::start();
  

  quill::Logger* logger = quill::get_logger();
  logger->set_log_level(quill::LogLevel::TraceL3);
  
  // enable a backtrace that will get flushed when we log CRITICAL
  logger->init_backtrace(2, quill::LogLevel::Critical);

  LOG_BACKTRACE(logger, "Backtrace log {}", 1);
  LOG_BACKTRACE(logger, "Backtrace log {}", 2);

  LOG_INFO(logger, "Welcome to Quill!");
  LOG_ERROR(logger, "An error message. error code {}", 123);
  LOG_WARNING(logger, "A warning message.");
  LOG_CRITICAL(logger, "A critical error.");
  LOG_DEBUG(logger, "Debugging foo {}", 1234);
  LOG_TRACE_L1(logger, "{:>30}", "right aligned");
  LOG_TRACE_L2(logger, "Positional arguments are {1} {0} ", "too", "supported");
  LOG_TRACE_L3(logger, "Support for floats {:03.2f}", 1.23456);

  return 0;
}