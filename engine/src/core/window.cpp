#include "engine/core/window.h"
#include "engine/core/log.h"

namespace engine
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

        LOG_CORE_INFO("Creating a window {} ({}x{})", m_data.title, m_data.height, m_data.width);
        
        if (!s_glfwInitialized)
        {
            int success = glfwInit();

            // TODO: Make an assert macro to handle errors
            //LOG_CORE_ERROR("Could not initialize GLFW!");

            s_glfwInitialized = true;
        }

        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title, NULL, NULL);
        if (m_window == NULL)
        {
            LOG_CORE_ERROR("Failed to create window!");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_window);
    }

    void Window::onUpdate()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();    
    }
}
