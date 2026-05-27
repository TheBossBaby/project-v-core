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

    class ILogger
    {
    public:
        virtual ~ILogger() = default;

        // Core function: log a message with a level
        virtual void log(LogLevel level, std::string_view message) = 0;

        // Optional convenience wrappers
        virtual void trace(std::string_view message)  = 0;
        virtual void info(std::string_view message)   = 0;
        virtual void warn(std::string_view message)   = 0;
        virtual void error(std::string_view message)  = 0;
        virtual void critical(std::string_view message) = 0;
    };
}