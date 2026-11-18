#pragma once

#include "engine/core/window.h"
#include "engine/core/log.h"
#include "engine/core/events/event_listener.h"
#include "engine/core/events/event.h"

namespace bk
{
    class App : public IEventListener
    {
    public:
        App();
        ~App();

        void onEvent(Event event) override;

        void run();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running;
    };
}
