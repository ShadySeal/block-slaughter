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

            // Event event(EventType::WINDOW_RESIZE);
            // event.resize.width = width;
            // event.resize.height = height;

            // self->dispatch(event);
        });

        // Close
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            // Event event(EventType::WINDOW_CLOSE);

            // self->dispatch(event);
        });

        // Keys
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key);
                    self->dispatchEvent(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    self->dispatchEvent(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyRepeatEvent event(key);
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
                    // Event event(EventType::MOUSE_BUTTON_PRESSED);
                    // self->dispatch(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    // Event event(EventType::MOUSE_BUTTON_RELEASED);
                    // self->dispatch(event);
                    break;
                }
            }
        });

        // Scroll
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            // Event event(EventType::MOUSE_SCROLLED);
            // event.scroll.x = xOffset;
            // event.scroll.y = yOffset;

            //self->dispatch(event);
        });

        // Cursor
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            // Event event(EventType::MOUSE_SCROLLED);
            // event.mouse.x = xPos;
            // event.mouse.y = yPos;

            //self->dispatch(event);
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
