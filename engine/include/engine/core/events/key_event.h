#pragma once

#include "event.h"

namespace bk
{
    class KeyEvent : public Event
    {
    public:
        KeyEvent(std::string name, int keyCode) : Event(name), m_keyCode(keyCode) {};
        int getKeyCode() { return m_keyCode; };
    
    private:
        int m_keyCode;
    };
}
