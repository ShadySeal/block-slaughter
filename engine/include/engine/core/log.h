#pragma once

#ifndef SPDLOG_ACTIVE_LEVEL
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace bk
{
    class Log
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_coreLogger;
        static std::shared_ptr<spdlog::logger> s_clientLogger;
    };
}

#ifndef NDEBUG
    // Core log macros
    #define BK_LOG_CORE_TRACE(...)  SPDLOG_LOGGER_TRACE(::bk::Log::getCoreLogger(), __VA_ARGS__)
    #define BK_LOG_CORE_DEBUG(...)  SPDLOG_LOGGER_DEBUG(::bk::Log::getCoreLogger(), __VA_ARGS__)
    #define BK_LOG_CORE_INFO(...)   SPDLOG_LOGGER_INFO(::bk::Log::getCoreLogger(), __VA_ARGS__)
    #define BK_LOG_CORE_WARN(...)   SPDLOG_LOGGER_WARN(::bk::Log::getCoreLogger(), __VA_ARGS__)
    #define BK_LOG_CORE_ERROR(...)  SPDLOG_LOGGER_ERROR(::bk::Log::getCoreLogger(), __VA_ARGS__)
    #define BK_LOG_CORE_FATAL(...)  SPDLOG_LOGGER_FATAL(::bk::Log::getCoreLogger(), __VA_ARGS__)

    // Client log macros
    #define BK_LOG_TRACE(...)       SPDLOG_LOGGER_TRACE(::bk::Log::getClientLogger(), __VA_ARGS__)
    #define BK_LOG_DEBUG(...)       SPDLOG_LOGGER_DEBUG(::bk::Log::getClientLogger(), __VA_ARGS__)
    #define BK_LOG_INFO(...)        SPDLOG_LOGGER_INFO(::bk::Log::getClientLogger(), __VA_ARGS__)
    #define BK_LOG_WARN(...)        SPDLOG_LOGGER_WARN(::bk::Log::getClientLogger(), __VA_ARGS__)
    #define BK_LOG_ERROR(...)       SPDLOG_LOGGER_ERROR(::bk::Log::getClientLogger(), __VA_ARGS__)
    #define BK_LOG_FATAL(...)       SPDLOG_LOGGER_FATAL(::bk::Log::getClientLogger(), __VA_ARGS__)
#else
    #define BK_LOG_CORE_TRACE(...)
    #define BK_LOG_CORE_DEBUG(...)
    #define BK_LOG_CORE_INFO(...)
    #define BK_LOG_CORE_WARN(...)
    #define BK_LOG_CORE_ERROR(...)
    #define BK_LOG_CORE_FATAL(...)

    #define BK_LOG_TRACE(...)
    #define BK_LOG_DEBUG(...)
    #define BK_LOG_INFO(...)
    #define BK_LOG_WARN(...)
    #define BK_LOG_ERROR(...)
    #define BK_LOG_FATAL(...)
#endif