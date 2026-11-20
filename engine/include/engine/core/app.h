#pragma once

#include "engine/core/window.h"
#include "engine/core/log.h"
#include "engine/core/events/event_listener.h"
#include "engine/core/events/event.h"
#include "engine/core/events/key_event.h"

namespace bk
{
    class App
    {
    public:
        App();
        ~App();

        void onInput(KeyEvent& event);

        void run();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running;
    };
}
