#include "engine/core/app.h"

namespace bk
{
    App::App()
    {
        m_window = std::make_unique<Window>();

        m_window->subcribe(this);
    }

    App::~App()
    {
        m_window->unsubscribe(this);
    }

    void App::onEvent(Event event)
    {
        if (event.type == EventType::WINDOW_RESIZE)
        {
            BK_LOG_CORE_DEBUG("Window was resized!!.");
        }
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
