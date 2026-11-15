#include <engine/core/app.h>
#include <engine/core/log.h>

int main()
{
    engine::Log::init();

    engine::App app;

    app.run();

    return 0;
}
