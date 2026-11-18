#include "engine/core/window.h"

namespace bk
{
    static bool s_glfwInitialized = false;

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

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

            self->m_data.width = width;
            self->m_data.height = height;

            Event event;
            event.type = EventType::WINDOW_RESIZE;
            event.resize.width = width;
            event.resize.height = height;

            self->dispatch(event);
        });
    }

    void Window::onUpdate()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}
