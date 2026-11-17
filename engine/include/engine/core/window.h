#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window_mode.h"
#include "window_props.h"
#include "assert.h"
#include "engine/core/log.h"

namespace brick
{
    class Window
    {
        public:
            Window(const WindowProps& props = WindowProps());
            ~Window();

            void onUpdate();

            unsigned int getWidth() { return m_data.width; };
            unsigned int getHeight() { return m_data.height; };

        private:
            GLFWwindow* m_window;

            struct WindowData
            {
                unsigned int width, height;
                const char* title;
                WindowMode mode;
            };

            WindowData m_data;

            void init(const WindowProps& props);
    };
}