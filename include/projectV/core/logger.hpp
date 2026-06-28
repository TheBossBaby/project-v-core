#pragma once

#include <string_view>

namespace projectv::core
{
    /**
     * @brief Severity levels used by the logging system.
     */
    enum class LogLevel
    {
        /** @brief Detailed diagnostic information. */
        Trace,

        /** @brief General informational messages. */
        Info,

        /** @brief Warning conditions that do not prevent execution. */
        Warn,

        /** @brief Error conditions indicating a failure in an operation. */
        Error,

        /** @brief Critical failures that may require application termination. */
        Critical
    };

    /**
     * @brief Defines the interface for logging messages.
     *
     * Implementations are responsible for routing log messages to one or
     * more output destinations such as the console, files, or external
     * logging services.
     */
    class ILogger
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~ILogger() = default;

        /**
         * @brief Logs a message with the specified severity level.
         *
         * @param level Severity level of the message.
         * @param message Message to log.
         */
        virtual void log(LogLevel level, std::string_view message) = 0;

        /**
         * @brief Logs a trace message.
         *
         * @param message Message to log.
         */
        virtual void trace(std::string_view message) = 0;

        /**
         * @brief Logs an informational message.
         *
         * @param message Message to log.
         */
        virtual void info(std::string_view message) = 0;

        /**
         * @brief Logs a warning message.
         *
         * @param message Message to log.
         */
        virtual void warn(std::string_view message) = 0;

        /**
         * @brief Logs an error message.
         *
         * @param message Message to log.
         */
        virtual void error(std::string_view message) = 0;

        /**
         * @brief Logs a critical message.
         *
         * @param message Message to log.
         */
        virtual void critical(std::string_view message) = 0;
    };
}