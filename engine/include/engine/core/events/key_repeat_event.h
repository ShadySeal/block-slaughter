#pragma once

#include "key_event.h"

namespace bk
{
    class KeyRepeatEvent : public KeyEvent
    {
    public:
        KeyRepeatEvent(int keyCode) : KeyEvent(keyCode) {}
    };
}