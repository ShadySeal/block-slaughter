#include "engine/core/log.h"

namespace bk
{
    std::shared_ptr<spdlog::logger> Log::s_coreLogger;
    std::shared_ptr<spdlog::logger> Log::s_clientLogger;

    void Log::init()
    {
        spdlog::set_pattern("%^[%T] [%l] %n: %v [%s:%#]%$");

        s_coreLogger = spdlog::stdout_color_mt("ENGINE");
        s_coreLogger->set_level(spdlog::level::trace);

        s_clientLogger = spdlog::stdout_color_mt("APP");
        s_clientLogger->set_level(spdlog::level::trace);

        BK_LOG_CORE_INFO("Initialized log.");
    }
}
