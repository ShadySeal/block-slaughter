#include <engine/core/app.h>
#include <engine/core/log.h>

int main()
{
    brick::Log::init();

    brick::App app;

    app.run();

    return 0;
}
