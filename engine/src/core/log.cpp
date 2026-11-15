#include "engine/core/log.h"

namespace engine
{
    std::shared_ptr<spdlog::logger> Log::_coreLogger;
    std::shared_ptr<spdlog::logger> Log::_clientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] [%l] %n: %v [%s:%#]%$");

        _coreLogger = spdlog::stdout_color_mt("ENGINE");
        _coreLogger->set_level(spdlog::level::trace);

        _clientLogger = spdlog::stdout_color_mt("APP");
        _clientLogger->set_level(spdlog::level::trace);

        LOG_CORE_INFO("Initialized log.");
    }
}
