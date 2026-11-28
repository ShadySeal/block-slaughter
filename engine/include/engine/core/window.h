#pragma once

#include "window_mode.h"
#include "window_props.h"
#include "engine/core/events/event.h"

struct GLFWwindow;

namespace bk
{
    class Window
    {
    public:
        Window(const WindowProps& props = WindowProps());
        ~Window();

        void pollEvents();
        void swapBuffers();

        int getWindowWidth() { return m_data.wWidth; };
        int getWindowHeight() { return m_data.wHeight; };
        int getFramebufferWidth() { return m_data.fWidth; };
        int getFramebufferHeight() { return m_data.fHeight; };

        void setEventCallback(const std::function<void(Event&)> callback) { m_data.eventCallback = callback; };

        GLFWwindow* getNativeWindow() const { return m_window; };

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