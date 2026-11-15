#pragma once

#ifndef SPDLOG_ACTIVE_LEVEL
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace engine
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
#define LOG_CORE_TRACE(...)  SPDLOG_LOGGER_TRACE(::engine::Log::getCoreLogger(), __VA_ARGS__)
#define LOG_CORE_DEBUG(...)  SPDLOG_LOGGER_DEBUG(::engine::Log::getCoreLogger(), __VA_ARGS__)
#define LOG_CORE_INFO(...)   SPDLOG_LOGGER_INFO(::engine::Log::getCoreLogger(), __VA_ARGS__)
#define LOG_CORE_WARN(...)   SPDLOG_LOGGER_WARN(::engine::Log::getCoreLogger(), __VA_ARGS__)
#define LOG_CORE_ERROR(...)  SPDLOG_LOGGER_ERROR(::engine::Log::getCoreLogger(), __VA_ARGS__)
#define LOG_CORE_FATAL(...)  SPDLOG_LOGGER_FATAL(::engine::Log::getCoreLogger(), __VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)       SPDLOG_LOGGER_TRACE(::engine::Log::getClientLogger(), __VA_ARGS__)
#define LOG_DEBUG(...)       SPDLOG_LOGGER_DEBUG(::engine::Log::getClientLogger(), __VA_ARGS__)
#define LOG_INFO(...)        SPDLOG_LOGGER_INFO(::engine::Log::getClientLogger(), __VA_ARGS__)
#define LOG_WARN(...)        SPDLOG_LOGGER_WARN(::engine::Log::getClientLogger(), __VA_ARGS__)
#define LOG_ERROR(...)       SPDLOG_LOGGER_ERROR(::engine::Log::getClientLogger(), __VA_ARGS__)
#define LOG_FATAL(...)       SPDLOG_LOGGER_FATAL(::engine::Log::getClientLogger(), __VA_ARGS__)
