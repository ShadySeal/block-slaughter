#pragma once

#include "key_event.h"

namespace bk
{
    class MouseReleasedEvent : public KeyEvent
    {
    public:
        MouseReleasedEvent(int keycode)
            : KeyEvent(keycode) {}
    };
}