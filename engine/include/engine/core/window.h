#pragma once

#include <GLFW/glfw3.h>
#include "window_mode.h"
#include "window_props.h"
#include "assert.h"
#include "engine/core/log.h"
#include "engine/core/events/event.h"
#include "engine/core/events/window_resize_event.h"
#include "engine/core/events/window_close_event.h"
#include "engine/core/events/mouse_scroll_event.h"
#include "engine/core/events/cursor_position_event.h"
#include "engine/core/events/key_pressed_event.h"
#include "engine/core/events/key_released_event.h"
#include "engine/core/events/mouse_pressed_event.h"
#include "engine/core/events/mouse_released_event.h"

namespace bk
{
    class Window
    {
    public:
        Window(const WindowProps& props = WindowProps());
        ~Window();

        void pollEvents();
        void swapBuffers();

        unsigned int getWidth() { return m_data.wWidth; };
        unsigned int getHeight() { return m_data.wHeight; };
        unsigned int getFramebufferWidth() { return m_data.fWidth; };
        unsigned int getFramebufferHeight() { return m_data.fHeight; };

        void setEventCallback(const std::function<void(Event&)> callback) { m_data.eventCallback = callback; };

    private:
        GLFWwindow* m_window;

        struct WindowData
        {
            int wWidth, wHeight;
            int fWidth, fHeight;
            const char* title;
            WindowMode mode;

            std::function<void(Event&)> eventCallback;
        };

        WindowData m_data;

        void init(const WindowProps& props);
        void setCallbacks();
    };
}