#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/core/window.h"

#include "engine/core/events/window_resize_event.h"
#include "engine/core/events/window_close_event.h"
#include "engine/core/events/mouse_scroll_event.h"
#include "engine/core/events/cursor_position_event.h"
#include "engine/core/events/key_pressed_event.h"
#include "engine/core/events/key_released_event.h"
#include "engine/core/events/mouse_pressed_event.h"
#include "engine/core/events/mouse_released_event.h"
#include "engine/core/assert.h"
#include "engine/core/log.h"

namespace bk
{
    static bool s_glfwInitialized = false;

    static void glfwErrorCallback(int error, const char* description)
    {
        BK_LOG_CORE_ERROR("GLFW Error({}): {}", error, description);
    }

    Window::Window(const WindowProps& props)
    {
        init(props);
    }

    Window::~Window()
    {
    }

    void Window::init(const WindowProps& props)
    {
        m_data.title = props.title;
        m_data.mode = props.mode;

        BK_LOG_CORE_INFO("Creating a window {} ({}x{})", m_data.title, props.width, props.height);
        
        if (!s_glfwInitialized)
        {
            int success = glfwInit();

            BK_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(glfwErrorCallback);

            s_glfwInitialized = true;
        }

        m_window = glfwCreateWindow(props.width, props.height, m_data.title, NULL, NULL);

        glfwGetWindowSize(m_window, &m_data.wWidth, &m_data.wHeight);
        glfwGetFramebufferSize(m_window, &m_data.fWidth, &m_data.fHeight);

        if (!m_window)
        {
            BK_LOG_CORE_ERROR("Failed to create window!");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_window);

        int loaded = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        BK_CORE_ASSERT(loaded, "Could not initialize GLAD!");

        glViewport(0, 0, m_data.wWidth, m_data.wHeight);

        glfwSetWindowUserPointer(m_window, &m_data);

        setCallbacks();
    }

    void Window::setCallbacks()
    {
        // Resize
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.wWidth = width;
            data.wHeight = height;
        });

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            data.fWidth = width;
            data.fHeight = height;

            glViewport(0, 0, width, height);

            WindowResizeEvent event(width, height);
            data.eventCallback(event);
        });

        // Close
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            WindowCloseEvent event;
            data.eventCallback(event);
        });

        // Keys
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key);
                    data.eventCallback(event);
                    break;
                }
            }
        });

        // Mouse
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            switch (action)
            {
                case GLFW_PRESS:
                {
                    MousePressedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseReleasedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
            }
        });

        // Scroll
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            MouseScrollEvent event((float)xOffset, (float)yOffset);
            data.eventCallback(event);
        });

        // Cursor
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            CursorPositionEvent event((float)xPos, (float)yPos);
            data.eventCallback(event);
        });
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_window);
    }
}
