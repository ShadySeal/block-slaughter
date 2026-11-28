#pragma once

#include "key_event.h"

namespace bk
{
    class MousePressedEvent : public KeyEvent
    {
    public:
        MousePressedEvent(int keycode)
            : KeyEvent(keycode) {}
    };
}