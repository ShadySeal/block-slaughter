#pragma once

#include <GLFW/glfw3.h>
#include "window_mode.h"
#include "window_props.h"
#include "assert.h"
#include "engine/core/log.h"
#include "engine/core/events/event_dispatcher.h"
#include "engine/core/events/key_event.h"
#include "engine/core/events/window_resize_event.h"
#include "engine/core/events/window_close_event.h"
#include "engine/core/events/mouse_scroll_event.h"
#include "engine/core/events/cursor_position_event.h"

namespace bk
{
    class Window
    {
    public:
        Window(const WindowProps& props = WindowProps());
        ~Window();

        void pollEvents();
        void swapBuffers();

        unsigned int getWidth() { return m_data.width; };
        unsigned int getHeight() { return m_data.height; };

        template <std::derived_from<Event> T>
        void subscribe(const std::string& name, std::function<void(T&)> callback)
        {
            m_dispatcher.subscribe<T>(name, callback);
        }

    private:
        GLFWwindow* m_window;

        struct WindowData
        {
            unsigned int width, height;
            const char* title;
            WindowMode mode;
        };

        WindowData m_data;
        EventDispatcher m_dispatcher;

        void init(const WindowProps& props);
        void setCallbacks();
        void dispatchEvent(Event& event) { m_dispatcher.dispatch(event); }
    };
}