#pragma once

#include "event.h"

namespace bk
{
    class MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(std::string name, float x, float y)
            : Event(name), m_scrollX(x), m_scrollY(y) {};
            
        float getScrollX() const { return m_scrollX; };
        float getScrollY() const { return m_scrollY; };
    
    private:
        float m_scrollX, m_scrollY;
    };
}
