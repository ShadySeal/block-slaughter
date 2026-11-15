#pragma once

#ifndef SPDLOG_ACTIVE_LEVEL
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace engine
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> _coreLogger;
        static std::shared_ptr<spdlog::logger> _clientLogger;
    };
}

// Core log macros
#define LOG_CORE_TRACE(...)  SPDLOG_LOGGER_TRACE(::engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_DEBUG(...)  SPDLOG_LOGGER_DEBUG(::engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_INFO(...)   SPDLOG_LOGGER_INFO(::engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_WARN(...)   SPDLOG_LOGGER_WARN(::engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_ERROR(...)  SPDLOG_LOGGER_ERROR(::engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_FATAL(...)  SPDLOG_LOGGER_FATAL(::engine::Log::GetCoreLogger(), __VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)       SPDLOG_LOGGER_TRACE(::engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_DEBUG(...)       SPDLOG_LOGGER_DEBUG(::engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_INFO(...)        SPDLOG_LOGGER_INFO(::engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_WARN(...)        SPDLOG_LOGGER_WARN(::engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_ERROR(...)       SPDLOG_LOGGER_ERROR(::engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_FATAL(...)       SPDLOG_LOGGER_FATAL(::engine::Log::GetClientLogger(), __VA_ARGS__)
