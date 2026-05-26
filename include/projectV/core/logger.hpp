#pragma once

#include <string_view>

namespace projectv::core
{
    enum class LogLevel
    {
        Trace,
        Info,
        Warn,
        Error,
        Critical
    };

    class Logger
    {
    public:
        static void log(LogLevel level, std::string_view message);

        static void trace(std::string_view message);
        static void info(std::string_view message);
        static void warn(std::string_view message);
        static void error(std::string_view message);
        static void critical(std::string_view message);
    };
}