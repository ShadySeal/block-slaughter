#pragma once

#include "key_event.h"

namespace bk
{
    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keyCode) : KeyEvent(keyCode) {}
    };
}