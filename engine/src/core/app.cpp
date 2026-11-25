#include "engine/core/app.h"

namespace bk
{
    App::App()
    {
        m_window = std::make_unique<Window>();

        m_window->setEventCallback(BIND_EVENT_FN(App::onEvent));
    }

    App::~App()
    {
        
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

    void App::onEvent(Event& event)
    {
        EventPropagator propagator(event);

        propagator.propagate<WindowCloseEvent>(BIND_EVENT_FN(App::onWindowClosed));
        propagator.propagate<WindowCloseEvent>(BIND_EVENT_FN(App::onWindowClosed));
        propagator.propagate<WindowResizeEvent>(BIND_EVENT_FN(App::onWindowResized));

        propagator.propagate<KeyEvent>(BIND_EVENT_FN(App::onKeyPressed));
        propagator.propagate<KeyEvent>(BIND_EVENT_FN(App::onKeyReleased));
        propagator.propagate<KeyEvent>(BIND_EVENT_FN(App::onKeyRepeated));

        propagator.propagate<KeyEvent>(BIND_EVENT_FN(App::onMousePressed));
        propagator.propagate<KeyEvent>(BIND_EVENT_FN(App::onMouseReleased));
        propagator.propagate<MouseScrollEvent>(BIND_EVENT_FN(App::onMouseScrolled));
        propagator.propagate<CursorPositionEvent>(BIND_EVENT_FN(App::onMousePosition));
    }

    void App::onWindowResized(WindowResizeEvent& event)
    {
        //BK_LOG_CORE_TRACE("Window resized: ({}x{})", event.getWidth(), event.getHeight());
    }

     void App::onWindowClosed(WindowCloseEvent& event)
    {
        m_running = false;
    }

    void App::onKeyPressed(KeyEvent& event)
    {
        //BK_LOG_CORE_INFO("Key pressed: {}", event.getKeyCode());
    }

    void App::onKeyReleased(KeyEvent& event)
    {
        //BK_LOG_CORE_INFO("Key released: {}", event.getKeyCode());
    }

    void App::onKeyRepeated(KeyEvent& event)
    {
        //BK_LOG_CORE_INFO("Key repeat: {}", event.getKeyCode());
    }

    void App::onMousePressed(KeyEvent& event)
    {
        //BK_LOG_CORE_INFO("Key pressed: {}", event.getKeyCode());
    }

    void App::onMouseReleased(KeyEvent& event)
    {
        //BK_LOG_CORE_INFO("Key released: {}", event.getKeyCode());
    }

    void App::onMouseScrolled(MouseScrollEvent& event)
    {
        //BK_LOG_CORE_INFO("Scroll direction: X: {}, Y: {}", event.getScrollX(), event.getScrollY());
    }

    void App::onMousePosition(CursorPositionEvent& event)
    {
        //BK_LOG_CORE_INFO("Mouse postion: X: {}, Y: {}", event.getPosX(), event.getPosY());
    }
}
