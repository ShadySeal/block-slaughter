#include "engine/core/app.h"

namespace brick
{
    App::App()
    {
        m_window = std::make_unique<Window>();
    }

    App::~App()
    {

    }

    void App::run()
    {
        m_running = true;

        while (m_running)
        {
            m_window->onUpdate();
        }
    }
}
