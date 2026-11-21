#pragma once

#include "key_event.h"

namespace bk
{
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}
    };
}