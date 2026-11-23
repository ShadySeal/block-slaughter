#include "engine/core/window.h"

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
        m_data.height = props.height;
        m_data.width = props.width;
        m_data.title = props.title;
        m_data.mode = props.mode;

        BK_LOG_CORE_INFO("Creating a window {} ({}x{})", m_data.title, m_data.height, m_data.width);
        
        if (!s_glfwInitialized)
        {
            int success = glfwInit();

            BK_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(glfwErrorCallback);

            s_glfwInitialized = true;
        }

        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title, NULL, NULL);
        if (!m_window)
        {
            BK_LOG_CORE_ERROR("Failed to create window!");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, this);

        setCallbacks();
    }

    void Window::setCallbacks()
    {
        // Resize
        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            self->m_data.width = width;
            self->m_data.height = height;

            WindowResizeEvent event("window_resize", width, height);

            self->dispatchEvent(event);
        });

        // Close
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            WindowCloseEvent event("window_close");

            self->dispatchEvent(event);
        });

        // Keys
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyEvent event("key_press", key);
                    self->dispatchEvent(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyEvent event("key_release", key);
                    self->dispatchEvent(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyEvent event("key_repeat", key);
                    self->dispatchEvent(event);
                    break;
                }
            }
        });

        // Mouse
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyEvent event("mouse_press", button);
                    self->dispatchEvent(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyEvent event("mouse_release", button);
                    self->dispatchEvent(event);
                    break;
                }
            }
        });

        // Scroll
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            MouseScrollEvent event("mouse_scroll", (float)xOffset, (float)yOffset);

            self->dispatchEvent(event);
        });

        // Cursor
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            CursorPositionEvent event("cursor_position", (float)xPos, (float)yPos);

            self->dispatchEvent(event);
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
