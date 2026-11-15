#include <engine/core/app.h>
#include <engine/core/log.h>

int main()
{
    engine::Log::Init();

    engine::App app;

    app.Run();

    return 0;
}
