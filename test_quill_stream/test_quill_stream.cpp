#include "quill/Quill.h"
#include "quill/detail/misc/FileUtilities.h"
#include <sstream>
#include <thread>
#include <chrono>
#include <list>
#include <unistd.h>

namespace dt
{

using log_clock = ::std::chrono::system_clock;

class Log
{
private:
    static std::string annotate_filename_datetime(const std::string file_basename)
    {
        quill::filename_t basename, ext, filename;

        time_t tnow = log_clock::to_time_t(log_clock::now());
        tm now_tm;
        quill::detail::localtime_rs(&tnow, &now_tm);

        std::pair<quill::filename_t, quill::filename_t> filename_pair = quill::detail::file_utilities::extract_stem_and_extension(file_basename);
        basename = filename_pair.first;
        ext = filename_pair.second;

        filename = fmt::format("{}_{:04d}-{:02d}-{:02d}_{:02d}-{:02d}-{:02d}{}", basename, now_tm.tm_year + 1900, now_tm.tm_mon + 1,
            now_tm.tm_mday, now_tm.tm_hour, now_tm.tm_min, now_tm.tm_sec, ext);

        return filename;
    }

    static std::tuple<std::string, std::string> split_by_directory(const std::string &fname)
    {
        auto dir_index = fname.rfind('/');

        // no valid directory found - return empty string as folder and whole path
        if (dir_index == std::string::npos)
        {
            return std::make_tuple(std::string(), fname);
        }
        // ends up with '/' - return whole path as directory and empty string as filename
        else if (dir_index == fname.size() - 1)
        {
            return std::make_tuple(fname, std::string());
        }

        // finally - return a valid directory and file path tuple
        return std::make_tuple(fname.substr(0, dir_index+1), fname.substr(dir_index+1)); // '/' is included as directory name
    }

public:
    enum class LogLevel {
        trace    = static_cast<int>(quill::LogLevel::TraceL3),
        debug    = static_cast<int>(quill::LogLevel::Debug),
        info     = static_cast<int>(quill::LogLevel::Info),
        warn     = static_cast<int>(quill::LogLevel::Warning),
        err      = static_cast<int>(quill::LogLevel::Error),
        critical = static_cast<int>(quill::LogLevel::Critical),
        off      = static_cast<int>(quill::LogLevel::None)
    };

public:
    static void Initialize(const std::string log_name, const std::string file_basename = "", bool annot_datetime = true, bool truncate = false) 
    {
        int rtn;
        if (file_basename.empty()) {
            quill::Handler* default_handler = quill::stdout_handler();
            quill::set_default_logger_handler(default_handler);
            quill::enable_console_colours();
            default_handler->set_pattern(
                QUILL_STRING("[%(level_id)][%(ascii_time)] %(message)"), // format
                "%D %H:%M:%S.%Qms",     // timestamp format
                quill::Timezone::LocalTime); // timestamp's timezone
            quill::start();
        }
        else {
            quill::filename_t filename = file_basename;
            if (annot_datetime)
                filename = annotate_filename_datetime(file_basename);

            quill::Handler* default_handler = quill::file_handler(filename, truncate ? std::string("w") : std::string("a"), quill::FilenameAppend::None);
            quill::set_default_logger_handler(default_handler);
            // quill::Logger* default_logger = quill::create_logger("__default_logger__");
            default_handler->set_pattern(
                QUILL_STRING("[%(level_id)][%(ascii_time)] %(message)"), // format
                "%H:%M:%S.%Qms",     // timestamp format
                quill::Timezone::LocalTime); // timestamp's timezone
            quill::start();
        }
    }

    static void Create(const std::string log_name, const std::string file_basename, bool annot_datetime = true, bool truncate = false)
    {
        quill::filename_t filename = file_basename;
        if (annot_datetime)
            filename = annotate_filename_datetime(file_basename);

        quill::Handler* file_handler = quill::file_handler(filename, truncate ? std::string("w") : std::string("a"), quill::FilenameAppend::None);
        file_handler->set_pattern(
            QUILL_STRING("[%(level_id)][%(ascii_time)] %(message)"), // format
            "%H:%M:%S.%Qms",     // timestamp format
            quill::Timezone::LocalTime); // timestamp's timezone

        // Create a logger
        quill::Logger* file_logger = quill::create_logger(log_name.c_str(), file_handler);
    }

    static void Flush(const std::string log_name)
    {
        // quill::Logger* logger = quill::get_logger(log_name);
        // if (logger)
        //     logger->flush();
        quill::flush();
    }

    static void FlushOn(const std::string log_name, LogLevel lvl)
    {
        
    }

    static void FlushOn(LogLevel lvl)
    {
        
    }

    static void Terminate() 
    {
        // flush all peding log message
        quill::flush();
    }

    static void SetLogLevel(const std::string log_name, LogLevel lvl) {
        quill::Logger* logger = quill::get_logger(log_name.c_str());
        if (logger) {
            logger->set_log_level(static_cast<quill::LogLevel>(lvl));
        }
    }

    static void SetLogLevel(LogLevel lvl) {
        quill::get_logger()->set_log_level(static_cast<quill::LogLevel>(lvl));
    }

    static void SetLogOff() {
        quill::get_logger()->set_log_level(quill::LogLevel::None);
    }

    typedef uint32_t LogPattern;

    class LogPatternFlag {
    public:
        enum _flag {
            none         = 0,
            type         = 0x0001,
            type_long    = 0x0002,
            date         = 0x0010,
            time         = 0x0020,
            datetime     = 0x0040,
            epoch        = 0x0080,
            elapsed      = 0x0100,
            name         = 0x0004,
        };
    };

    static void SetLogPattern(const std::string log_name, LogPattern ptn = LogPatternFlag::type|LogPatternFlag::time , const std::string delimitter = "|") {
        std::string pattern = "";
        std::string time_fmt = "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::type))      ? std::string("%(level_id)") + delimitter : 
                   (ptn & static_cast<LogPattern>(LogPatternFlag::type_long)) ? std::string("%(level_name)") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::date) || ptn & static_cast<LogPattern>(LogPatternFlag::time) || ptn & static_cast<LogPattern>(LogPatternFlag::datetime)) ? std::string("%(ascii_time)") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::name))      ? std::string("%(logger_name)") + delimitter : "";
        pattern += "%(message)";

        time_fmt = (ptn & static_cast<LogPattern>(LogPatternFlag::date))      ? std::string("%D"):
                   (ptn & static_cast<LogPattern>(LogPatternFlag::time))      ? std::string("%H:%M:%S.%Qns"):
                   (ptn & static_cast<LogPattern>(LogPatternFlag::datetime))  ? std::string("%D %H:%M:%S.%Qns") : "";

        // file_handler->set_pattern(
        //     QUILL_STRING(pattern), // format
        //     time_ftm,     // timestamp format
        //     quill::Timezone::LocalTime); // timestamp's timezone
    }

    static void SetLogPattern(LogPattern ptn = LogPatternFlag::type|LogPatternFlag::time, const std::string delimitter = "|") {
        std::string pattern = "";
        std::string time_fmt = "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::type))      ? std::string("%(level_id)") + delimitter : 
                   (ptn & static_cast<LogPattern>(LogPatternFlag::type_long)) ? std::string("%(level_name)") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::date) || ptn & static_cast<LogPattern>(LogPatternFlag::time) || ptn & static_cast<LogPattern>(LogPatternFlag::datetime)) ? std::string("%(ascii_time)") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::name))      ? std::string("%(logger_name)") + delimitter : "";
        pattern += "%(message)";

        time_fmt = (ptn & static_cast<LogPattern>(LogPatternFlag::date))      ? std::string("%D"):
                   (ptn & static_cast<LogPattern>(LogPatternFlag::time))      ? std::string("%H:%M:%S.%Qns"):
                   (ptn & static_cast<LogPattern>(LogPatternFlag::datetime))  ? std::string("%D %H:%M:%S.%Qns") : "";
        
        // file_handler->set_pattern(
        //     QUILL_STRING(pattern), // format
        //     time_ftm,     // timestamp format
        //     quill::Timezone::LocalTime); // timestamp's timezone
    }

public:
    class LogStream {
    public:
        explicit LogStream(const LogLevel log_level)
            : _log_level(log_level) {
        }
        template <typename T>
        LogStream& operator<<(const T& value) {
            _log_stream << value;
            return *this;
        }
        template<typename TFormatString, typename... FmtArgs>
        inline void format(TFormatString fmt_string, FmtArgs &&...fmt_args)
        {
            _log_stream << fmt::format(fmt_string, std::forward<FmtArgs>(fmt_args)...);
        }
        ~LogStream() {
            switch(_log_level) {
                case LogLevel::trace:
                    QUILL_LOG_TRACE_L3(quill::get_logger(), "{}", _log_stream.str()); break;
                case LogLevel::debug:
                    QUILL_LOG_DEBUG(quill::get_logger(), "{}", _log_stream.str()); break;
                case LogLevel::info:
                    QUILL_LOG_INFO(quill::get_logger(), "{}", _log_stream.str()); break;
                case LogLevel::warn:
                    QUILL_LOG_WARNING(quill::get_logger(), "{}", _log_stream.str()); break;
                case LogLevel::err:
                    QUILL_LOG_ERROR(quill::get_logger(), "{}", _log_stream.str()); break;
                case LogLevel::critical:
                    QUILL_LOG_CRITICAL(quill::get_logger(), "{}", _log_stream.str()); break;
                case LogLevel::off:
                    break;
            };
        }
    private:
        LogLevel _log_level;
        std::ostringstream _log_stream;
    };

    class NamedLogStream {
    public:
        explicit NamedLogStream(const std::string log_name, const LogLevel log_level)
            : _log_name(log_name), _log_level(log_level) {
        }
        template <typename T>
        NamedLogStream& operator<<(const T& value) {
            _log_stream << value;
            return *this;
        }
        template<typename TFormatString, typename... FmtArgs>
        inline void format(TFormatString fmt_string, FmtArgs &&...fmt_args)
        {
            _log_stream << fmt::format(fmt_string, std::forward<FmtArgs>(fmt_args)...);
        }
        ~NamedLogStream() {
            quill::Logger* logger = quill::get_logger(_log_name.c_str());
            if (logger) {
                switch(_log_level) {
                    case LogLevel::trace:
                        QUILL_LOG_TRACE_L3(logger, "{}", _log_stream.str()); break;
                    case LogLevel::debug:
                        QUILL_LOG_DEBUG(logger, "{}", _log_stream.str()); break;
                    case LogLevel::info:
                        QUILL_LOG_INFO(logger, "{}", _log_stream.str()); break;
                    case LogLevel::warn:
                        QUILL_LOG_WARNING(logger, "{}", _log_stream.str()); break;
                    case LogLevel::err:
                        QUILL_LOG_ERROR(logger, "{}", _log_stream.str()); break;
                    case LogLevel::critical:
                        QUILL_LOG_CRITICAL(logger, "{}", _log_stream.str()); break;
                    case LogLevel::off:
                        break;
                };
            }
        }
    private:
        std::string _log_name{};
        LogLevel _log_level;
        std::ostringstream _log_stream;
    };

};

} // namespace dt

/* Might cause macro redefinition errors, you can comment them out if needed */
// #define INFO info
// #define WARNING warn
// #define ERROR err

// dt::Log to quill converter
#define LOG_S(log_level) dt::Log::LogStream(dt::Log::LogLevel::log_level)
#define LOG_U_S(log_name, log_level) dt::Log::NamedLogStream(#log_name, dt::Log::LogLevel::log_level)

// log to default logger
#define LOG(log_level) LOG_S(log_level)
// log to user-added log file
#define LOG_U(log_name, log_level) LOG_U_S(log_name, log_level)

std::function<double(void)> gen = [] (void) -> double {
    return (rand() / (double)RAND_MAX);
};

int main() {
    using namespace dt;

    dt::Log::Initialize("test_spdlog_stream");
    // dt::Log::Initialize("test_quill_stream", "logs/test_quill_stream.txt");
    dt::Log::SetLogLevel(dt::Log::LogLevel::trace);

    // log to default logger
    LOG(trace) << "This is a trace message: " << 42;
    LOG(debug) << "This is a debug message: " << 42;
    LOG(info) << "This is an info message: " << 42;
    LOG(warn) << "This is a warning message.";
    LOG(err) << "This is an error message.";
    LOG(critical) << "This is a critical error message.";

    LOG(info) << "This is from format string: " << fmt::format("{0:} {0:}", 1.234);
    LOG(err).format("This is from format string(err): {0:} {1:}", 1.234, 90); 

    // User custom log
    dt::Log::Create("my_log", "logs/test_quill_stream_mylog.txt");
    dt::Log::SetLogLevel("my_log", dt::Log::LogLevel::trace);
    // dtLdt::Logog::SetLogPattern("my_log", dt::Log::LogPatternFlag::epoch);
    LOG_U(my_log, trace) << "This is a user trace message: " << 42;
    LOG_U(my_log, debug) << "This is a user debug message: " << 42;
    LOG_U(my_log, info) << "This is a user info message: " << 42;
    LOG_U(my_log, warn) << "This is a user warning message.";
    LOG_U(my_log, err) << "This is a user error message.";
    LOG_U(my_log, critical) << "This is a user critical error message.";

    LOG_U(my_log, info) << "This is a user format string: " << fmt::format("{0:} {0:}", 1.234);
    LOG_U(my_log, err).format("This is a user format error string: {0:} {1:}", 1.234, 90);

    // Thread test
    std::list<std::thread> threads;
    std::function<void(int)> thread_func = [] (int tid) {
        int run = 50000;
        while (run-- > 0) {
            LOG_U(my_log, info).format("{{{}}} -> {:.3},{:.3},{:.3},{:.3},{:.3}", tid, gen(), gen(), gen(), gen(), gen());
            //std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    };
    const int thread_count = 30;
    for (int i=0; i<thread_count; i++) {
        threads.push_back(std::thread(thread_func, i));
    }
    // for (std::thread th : threads) {
    //     if (th.joinable()) th.join();
    // }
    for (std::list<std::thread>::iterator th = threads.begin(); th != threads.end(); th++) {
        if ((*th).joinable())
            th->join();
    }

    return EXIT_SUCCESS;
}