#pragma once

#include "engine/core/window.h"
#include "engine/core/log.h"
#include "engine/core/events/event_propagator.h"
#include "engine/core/events/key_event.h"
#include "engine/core/events/window_resize_event.h"
#include "engine/core/events/window_close_event.h"
#include "engine/core/events/mouse_scroll_event.h"
#include "engine/core/events/cursor_position_event.h"

namespace bk
{
    class App
    {
    public:
        App();
        ~App();

        void run();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running;

        void onEvent(Event& event);

        // Events
        void onWindowResized(WindowResizeEvent& event);
        void onWindowClosed(WindowCloseEvent& event);
        void onKeyPressed(KeyEvent& event);
        void onKeyReleased(KeyEvent& event);
        void onKeyRepeated(KeyEvent& event);
        void onMousePressed(KeyEvent& event);
        void onMouseReleased(KeyEvent& event);
        void onMouseScrolled(MouseScrollEvent& event);
        void onMousePosition(CursorPositionEvent& event);
    };
}
