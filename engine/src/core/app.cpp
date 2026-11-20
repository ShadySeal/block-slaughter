#include "engine/core/app.h"

namespace bk
{
    App::App()
    {
        m_window = std::make_unique<Window>();

        m_window->subscribe<KeyEvent>([this](KeyEvent& event) { onInput(event); });
    }

    App::~App()
    {
        //m_window->unsubscribe(this);
    }

    // void App::onEvent(Event event)
    // {
    //     switch (event.type)
    //     {
    //         case EventType::WINDOW_CLOSE:
    //         {
    //             m_running = false;
    //             break;
    //         }
    //         case EventType::KEY_PRESSED:
    //         {
    //             BK_LOG_CORE_TRACE("Key: {}", event.key.key);
                
    //             break;
    //         }
    //     }
    // }

    void App::onInput(KeyEvent& event)
    {
        BK_LOG_CORE_INFO("Key: {}", event.getKey());
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
}
