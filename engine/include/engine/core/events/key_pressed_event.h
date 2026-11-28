#pragma once

#include "key_event.h"

namespace bk
{
    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode)
            : KeyEvent(keycode) {}
    };
}