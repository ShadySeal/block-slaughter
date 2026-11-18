#include <engine/core/app.h>
#include <engine/core/log.h>

int main()
{
    bk::Log::init();

    bk::App app;

    app.run();

    return 0;
}
