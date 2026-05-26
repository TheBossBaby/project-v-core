#include "projectV/core/logger.hpp"

#include <iostream>
#include <mutex>

namespace projectv::core
{
    namespace
    {
        std::mutex g_logMutex;

        const char* to_string(LogLevel level)
        {
            switch (level)
            {
            case LogLevel::Trace:    return "TRACE";
            case LogLevel::Info:     return "INFO";
            case LogLevel::Warn:     return "WARN";
            case LogLevel::Error:    return "ERROR";
            case LogLevel::Critical: return "CRITICAL";
            default:                 return "UNKNOWN";
            }
        }
    }

    void Logger::log(LogLevel level, std::string_view message)
    {
        std::lock_guard<std::mutex> lock(g_logMutex);

        std::cout << "[" << to_string(level) << "] " << message << std::endl;
    }

    void Logger::trace(std::string_view message)
    {
        log(LogLevel::Trace, message);
    }

    void Logger::info(std::string_view message)
    {
        log(LogLevel::Info, message);
    }

    void Logger::warn(std::string_view message)
    {
        log(LogLevel::Warn, message);
    }

    void Logger::error(std::string_view message)
    {
        log(LogLevel::Error, message);
    }

    void Logger::critical(std::string_view message)
    {
        log(LogLevel::Critical, message);
    }
}