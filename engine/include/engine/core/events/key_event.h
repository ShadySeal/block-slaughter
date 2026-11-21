#pragma once

#include "event.h"

namespace bk
{
    class KeyEvent : public Event
    {
    public:
        int getKeyCode() { return m_keyCode; };
    
    protected:
        KeyEvent(int keyCode) : m_keyCode(keyCode) {};
        const int m_keyCode;
    };
}
