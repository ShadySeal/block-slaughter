#pragma once

#include "engine/core/window.h"
#include "engine/core/log.h"
#include "engine/core/events/event_propagator.h"
#include "engine/core/events/window_close_event.h"
#include "engine/core/layer.h"
#include "engine/core/layer_stack.h"

namespace bk
{
    class App
    {
    public:
        App();
        ~App();

        void run();

        void onEvent(Event& event);

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* layer);

        Window& getWindow() { return *m_window; };

        static App& get() { return *s_instance; };

    private:
        static App* s_instance;

        std::unique_ptr<Window> m_window;
        bool m_running;
        LayerStack m_layerStack;

        void onWindowClosed(WindowCloseEvent& event);
    };
}
