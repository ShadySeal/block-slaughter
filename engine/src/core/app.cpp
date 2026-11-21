#include "engine/core/app.h"

namespace bk
{
    App::App()
    {
        m_window = std::make_unique<Window>();

        m_window->subscribe<KeyPressedEvent>(BIND_EVENT_FN(App::onKeyPressed));
        m_window->subscribe<KeyReleasedEvent>(BIND_EVENT_FN(App::onKeyReleased));
        m_window->subscribe<KeyRepeatEvent>(BIND_EVENT_FN(App::onKeyRepeat));
    }

    App::~App()
    {
        //m_window->unsubscribe(this);
    }

    void App::run()
    {
        m_running = true;

        while (m_running)
        {
            m_window->pollEvents();
            m_window->swapBuffers();
        }
    }

    void App::onKeyPressed(KeyPressedEvent& event)
    {
        BK_LOG_CORE_INFO("Key pressed: {}", event.getKeyCode());
    }

    void App::onKeyReleased(KeyReleasedEvent& event)
    {
        BK_LOG_CORE_INFO("Key released: {}", event.getKeyCode());
    }

    void App::onKeyRepeat(KeyRepeatEvent& event)
    {
        BK_LOG_CORE_INFO("Key repeat: {}", event.getKeyCode());
    }
}
