#include <glad/glad.h>

#include "engine/core/app.h"

#include "engine/core/assert.h"

namespace bk
{
    App* App::s_instance = nullptr;

    App::App()
    {
        BK_CORE_ASSERT(!s_instance, "Application already exists!")
        s_instance = this;

        m_window = std::make_unique<Window>();
        m_window->setEventCallback(BIND_EVENT_FN(App::onEvent));
    }

    App::~App()
    {
        
    }

    void App::run()
    {
        m_running = true;

        while (m_running)
        {
            glClearColor(0, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_layerStack)
            {
                layer->onUpdate();
            }

            m_window->pollEvents();
            m_window->swapBuffers();
        }
    }

    void App::onEvent(Event& event)
    {
        EventPropagator propagator(event);

        propagator.propagate<WindowCloseEvent>(BIND_EVENT_FN(App::onWindowClosed));

        for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
        {
            (*--it)->onEvent(event);
            if (event.isHandled())
            {
                break;
            }
        }
    }

    void App::pushLayer(Layer* layer)
    {
        m_layerStack.pushLayer(layer);
        layer->onAttach();
    }

    void App::pushOverlay(Layer* layer)
    {
        m_layerStack.pushOverlay(layer);
        layer->onAttach();
    }

     void App::onWindowClosed(WindowCloseEvent& event)
    {
        m_running = false;
    }
}
