#include "engine/core/app.h"

namespace bk
{
    App::App()
    {
        m_window = std::make_unique<Window>();

        m_window->subscribe<WindowResizeEvent>("window_resize", BIND_EVENT_FN(App::onWindowResized));
        m_window->subscribe<WindowCloseEvent>("window_close", BIND_EVENT_FN(App::onWindowClosed));
        m_window->subscribe<KeyEvent>("key_press", BIND_EVENT_FN(App::onKeyPressed));
        m_window->subscribe<KeyEvent>("key_release", BIND_EVENT_FN(App::onKeyReleased));
        m_window->subscribe<KeyEvent>("key_repeat", BIND_EVENT_FN(App::onKeyRepeated));
        m_window->subscribe<KeyEvent>("mouse_press", BIND_EVENT_FN(App::onMousePressed));
        m_window->subscribe<KeyEvent>("mouse_release", BIND_EVENT_FN(App::onMouseReleased));
        m_window->subscribe<MouseScrollEvent>("mouse_scroll", BIND_EVENT_FN(App::onMouseScrolled));
        m_window->subscribe<CursorPositionEvent>("cursor_position", BIND_EVENT_FN(App::onMousePosition));
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
