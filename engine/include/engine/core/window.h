#pragma once

#include <GLFW/glfw3.h>
#include "window_mode.h"
#include "window_props.h"
#include "assert.h"
#include "engine/core/log.h"
#include "engine/core/events/event_dispatcher.h"
#include "engine/core/events/key_pressed_event.h"
#include "engine/core/events/key_released_event.h"
#include "engine/core/events/key_repeat_event.h"

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
        void subscribe(std::function<void(T&)> callback)
        {
            m_dispatcher.subscribe<T>(std::move(callback));
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