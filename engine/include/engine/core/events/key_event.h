#pragma once

#include "event.h"

namespace bk
{
    class KeyEvent : public Event
    {
    public:
        KeyEvent(int key) : m_key(key) {};
        int getKey() { return m_key; };
    
    private:
        const int m_key;
    };
}
