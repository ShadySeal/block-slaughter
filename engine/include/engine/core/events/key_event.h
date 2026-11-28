#pragma once

#include "event.h"

namespace bk
{
    class KeyEvent : public Event
    {
    public:
        int getKeyCode() const { return m_keyCode; };
    
    protected:
        KeyEvent(int keyCode)
            : m_keyCode(keyCode) {};
            
        int m_keyCode;
    };
}
