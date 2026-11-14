#pragma once

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
#define LOG_CORE_TRACE(...)   ::engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)    ::engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)    ::engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)   ::engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...)   ::engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)        ::engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)         ::engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)         ::engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)        ::engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)        ::engine::Log::GetClientLogger()->fatal(__VA_ARGS__)
