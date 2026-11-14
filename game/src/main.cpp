#include <engine/core/app.h>
#include <engine/core/log.h>

int main()
{
    engine::Log::Init();
    LOG_CORE_WARN("Initialized log!");
    int a = 5;
    LOG_INFO("Hello! Var={0}", a);

    engine::App app;

    app.Run();

    return 0;
}
