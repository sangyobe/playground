//#define SPDLOG_COMPILED_LIB 1
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
//#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/spdlog.h>
#include <spdlog/details/os.h>
#include <sstream>
#include <thread>
#include <chrono>
#include <list>
#include <unistd.h>

#define DTCORE_DTLOG_MT

namespace dt
{

using log_clock = ::std::chrono::system_clock;

class Log
{
private:
    static std::string annotate_filename_datetime(const std::string file_basename)
    {
        spdlog::filename_t basename, ext, filename;

        time_t tnow = log_clock::to_time_t(log_clock::now());
        tm now_tm = spdlog::details::os::localtime(tnow);
        
        std::tie(basename, ext) = spdlog::details::file_helper::split_by_extension(file_basename);

        filename = fmt::format(SPDLOG_FILENAME_T("{}_{:04d}-{:02d}-{:02d}_{:02d}-{:02d}-{:02d}{}"), basename, now_tm.tm_year + 1900, now_tm.tm_mon + 1,
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
        trace = spdlog::level::trace,
        debug = spdlog::level::debug, 
        info = spdlog::level::info, 
        warn = spdlog::level::warn, 
        err = spdlog::level::err, 
        critical = spdlog::level::critical, 
        off = spdlog::level::off
    };

    static void Initialize(const std::string log_name, const std::string file_basename = "", bool annot_datetime = true, bool truncate = false) 
    {
        int rtn;
        std::shared_ptr<spdlog::logger> logger{nullptr};
        // Create a logger
        if (file_basename.empty()) {
#ifdef DTCORE_DTLOG_MT
            logger = spdlog::stdout_color_mt(log_name);
#else
            logger = spdlog::stdout_color_st(log_name);
#endif 
        }
        else {
            spdlog::filename_t filename = file_basename;
            if (annot_datetime)
                filename = annotate_filename_datetime(file_basename);
#ifdef DTCORE_DTLOG_MT
            logger = spdlog::basic_logger_mt(log_name, filename, truncate);
#else
            logger = spdlog::basic_logger_st(log_name, filename, truncate);
#endif
            if (annot_datetime) {
                std::string dname, fname;
                std::tie(dname, fname) = split_by_directory(filename);
                rtn = remove(file_basename.c_str());
                if (0 > rtn) logger->log(spdlog::level::warn, "{} Cannot remove previous symlink.", rtn);
                rtn = symlink(fname.c_str(), file_basename.c_str());
                if (0 > rtn) logger->log(spdlog::level::warn, "{} Cannot create symlink to this log file.", rtn);
            }
        }
        logger->set_pattern("%^[%L][%H:%M:%S.%f]%$%v");
        spdlog::set_default_logger(logger);
    }

    static void Create(const std::string log_name, const std::string file_basename, bool annot_datetime = true, bool truncate = false)
    {
        int rtn;
        spdlog::filename_t filename = file_basename;
        if (annot_datetime)
            filename = annotate_filename_datetime(file_basename);

        // Create a logger
#ifdef DTCORE_DTLOG_MT
        auto logger = spdlog::basic_logger_mt(log_name, filename, truncate);
#else
        auto logger = spdlog::basic_logger_st(log_name, filename, truncate);
#endif
        if (annot_datetime) {
            std::string dname, fname;
            std::tie(dname, fname) = split_by_directory(filename);
            rtn = remove(file_basename.c_str());
            if (0 > rtn) logger->log(spdlog::level::warn, "{} Cannot remove previous symlink.", rtn);
            rtn = symlink(fname.c_str(), file_basename.c_str());
            if (0 > rtn) logger->log(spdlog::level::warn, "{} Cannot create symlink to this log file.", rtn);
        }
        logger->set_pattern("%^[%L][%H:%M:%S.%f]%$%v");
    }

    static void Flush(const std::string log_name)
    {
        std::shared_ptr<spdlog::logger> logger = spdlog::get(log_name);
        if (logger)
            logger->flush();
    }

    static void FlushOn(const std::string log_name, LogLevel lvl)
    {
        std::shared_ptr<spdlog::logger> logger = spdlog::get(log_name);
        if (logger)
            logger->flush_on(static_cast<spdlog::level::level_enum>(lvl));
    }

    static void FlushOn(LogLevel lvl)
    {
        spdlog::flush_on(static_cast<spdlog::level::level_enum>(lvl));
    }

    static void Terminate() 
    {
        // flush all peding log message
        spdlog::shutdown();
    }

    static void SetLogLevel(const std::string log_name, LogLevel lvl) {
        std::shared_ptr<spdlog::logger> logger = spdlog::get(log_name);
        if (logger) {
            logger->set_level(static_cast<spdlog::level::level_enum>(lvl));
        }
    }

    static void SetLogLevel(LogLevel lvl) {
        spdlog::set_level(static_cast<spdlog::level::level_enum>(lvl));
    }

    static void SetLogOff() {
        spdlog::set_level(spdlog::level::off);
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
        std::shared_ptr<spdlog::logger> logger = spdlog::get(log_name);
        std::string pattern = "%^";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::type))      ? std::string("%L") + delimitter : 
                   (ptn & static_cast<LogPattern>(LogPatternFlag::type_long)) ? std::string("%l") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::date))      ? std::string("%Y-%m-%d") + delimitter :
                   (ptn & static_cast<LogPattern>(LogPatternFlag::time))      ? std::string("%H:%M:%S.%f") + delimitter :
                   (ptn & static_cast<LogPattern>(LogPatternFlag::datetime))  ? std::string("%Y-%m-%d %H:%M:%S.%f") + delimitter : 
                   (ptn & static_cast<LogPattern>(LogPatternFlag::epoch))     ? std::string("%E.%f") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::elapsed))   ? std::string("%8i") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::name))      ? std::string("%n") + delimitter : "";
        pattern += "%$%v";
        if (logger) {
            logger->set_pattern(pattern);
        }
    }

    static void SetLogPattern(LogPattern ptn = LogPatternFlag::type|LogPatternFlag::time, const std::string delimitter = "|") {
        std::string pattern = "%^";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::type))      ? std::string("%L") + delimitter : 
                   (ptn & static_cast<LogPattern>(LogPatternFlag::type_long)) ? std::string("%l") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::date))      ? std::string("%Y-%m-%d") + delimitter :
                   (ptn & static_cast<LogPattern>(LogPatternFlag::time))      ? std::string("%H:%M:%S.%f") + delimitter :
                   (ptn & static_cast<LogPattern>(LogPatternFlag::datetime))  ? std::string("%Y-%m-%d %H:%M:%S.%f") + delimitter : 
                   (ptn & static_cast<LogPattern>(LogPatternFlag::epoch))     ? std::string("%E.%f") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::elapsed))   ? std::string("%8i") + delimitter : "";
        pattern += (ptn & static_cast<LogPattern>(LogPatternFlag::name))      ? std::string("%n") + delimitter : "";
        pattern += "%$%v";
        spdlog::set_pattern(pattern);
    }

public:
    class LogStream {
    public:
        explicit LogStream(const spdlog::level::level_enum log_level)
            : _log_level(log_level) {
        }
        template <typename T>
        LogStream& operator<<(const T& value) {
            _log_stream << value;
            return *this;
        }
        template<typename... Args>
        inline void format(spdlog::format_string_t<Args...> fmt_string, Args &&...args)
        {
            _log_stream << fmt::format(fmt_string, std::forward<Args>(args)...);
        }
        ~LogStream() {
            spdlog::log(_log_level, "{}", _log_stream.str());
        }
    private:
        spdlog::level::level_enum _log_level;
        std::ostringstream _log_stream;
    };

    class NamedLogStream {
    public:
        explicit NamedLogStream(const std::string log_name, const spdlog::level::level_enum log_level)
            : _log_name(log_name), _log_level(log_level) {
        }
        template <typename T>
        NamedLogStream& operator<<(const T& value) {
            _log_stream << value;
            return *this;
        }
        template<typename... Args>
        inline void format(spdlog::format_string_t<Args...> fmt_string, Args &&...args)
        {
            _log_stream << fmt::format(fmt_string, std::forward<Args>(args)...);
        }
        ~NamedLogStream() {
            std::shared_ptr<spdlog::logger> logger = spdlog::get(_log_name);
            if (logger)
                logger->log(_log_level, "{}", _log_stream.str());
            else
                spdlog::log(_log_level, "{}", _log_stream.str());
        }
    private:
        std::string _log_name{};
        spdlog::level::level_enum _log_level;
        std::ostringstream _log_stream;
    };

};

} // namespace dt

/* Might cause macro redefinition errors, you can comment them out if needed */
// #define INFO info
// #define WARNING warn
// #define ERROR err

// dt::Log to spdlog converter
#define LOG_S(log_level) dt::Log::LogStream(spdlog::level::log_level)
#define LOG_U_S(log_name, log_level) dt::Log::NamedLogStream(#log_name, spdlog::level::log_level)

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
    //dt::Log::Initialize("test_spdlog_stream", "logs/test_spdlog_stream.txt");
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
    dt::Log::Create("my_log", "logs/test_spdlog_stream_mylog.txt");
    dt::Log::SetLogLevel("my_log", dt::Log::LogLevel::trace);
    // dt::Log::SetLogPattern("my_log", dt::Log::LogPatternFlag::epoch);
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