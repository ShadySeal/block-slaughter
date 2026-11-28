#include <engine/core/app.h>
#include <engine/core/log.h>
#include <engine/debug/imgui_layer.h>

int main()
{
    bk::Log::init();

    bk::App app;

    app.pushOverlay(new bk::ImGuiLayer());

    app.run();

    return 0;
}
