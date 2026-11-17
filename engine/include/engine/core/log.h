#pragma once

#ifndef SPDLOG_ACTIVE_LEVEL
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace brick
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

// Core log macros
#define BK_LOG_CORE_TRACE(...)  SPDLOG_LOGGER_TRACE(::brick::Log::getCoreLogger(), __VA_ARGS__)
#define BK_LOG_CORE_DEBUG(...)  SPDLOG_LOGGER_DEBUG(::brick::Log::getCoreLogger(), __VA_ARGS__)
#define BK_LOG_CORE_INFO(...)   SPDLOG_LOGGER_INFO(::brick::Log::getCoreLogger(), __VA_ARGS__)
#define BK_LOG_CORE_WARN(...)   SPDLOG_LOGGER_WARN(::brick::Log::getCoreLogger(), __VA_ARGS__)
#define BK_LOG_CORE_ERROR(...)  SPDLOG_LOGGER_ERROR(::brick::Log::getCoreLogger(), __VA_ARGS__)
#define BK_LOG_CORE_FATAL(...)  SPDLOG_LOGGER_FATAL(::brick::Log::getCoreLogger(), __VA_ARGS__)

// Client log macros
#define BK_LOG_TRACE(...)       SPDLOG_LOGGER_TRACE(::brick::Log::getClientLogger(), __VA_ARGS__)
#define BK_LOG_DEBUG(...)       SPDLOG_LOGGER_DEBUG(::brick::Log::getClientLogger(), __VA_ARGS__)
#define BK_LOG_INFO(...)        SPDLOG_LOGGER_INFO(::brick::Log::getClientLogger(), __VA_ARGS__)
#define BK_LOG_WARN(...)        SPDLOG_LOGGER_WARN(::brick::Log::getClientLogger(), __VA_ARGS__)
#define BK_LOG_ERROR(...)       SPDLOG_LOGGER_ERROR(::brick::Log::getClientLogger(), __VA_ARGS__)
#define BK_LOG_FATAL(...)       SPDLOG_LOGGER_FATAL(::brick::Log::getClientLogger(), __VA_ARGS__)
