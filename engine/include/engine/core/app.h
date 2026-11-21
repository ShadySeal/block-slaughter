#pragma once

#include "engine/core/window.h"
#include "engine/core/log.h"
#include "engine/core/events/event.h"
#include "engine/core/events/key_pressed_event.h"
#include "engine/core/events/key_released_event.h"
#include "engine/core/events/key_repeat_event.h"

namespace bk
{
    class App
    {
    public:
        App();
        ~App();

        void run();

        // Events
        void onKeyPressed(KeyPressedEvent& event);
        void onKeyReleased(KeyReleasedEvent& event);
        void onKeyRepeat(KeyRepeatEvent& event);

    private:
        std::unique_ptr<Window> m_window;
        bool m_running;
    };
}
