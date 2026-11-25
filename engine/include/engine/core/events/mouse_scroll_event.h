#pragma once

#include "event.h"

namespace bk
{
    class MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(float x, float y)
            : m_scrollX(x), m_scrollY(y) {};
            
        float getScrollX() const { return m_scrollX; };
        float getScrollY() const { return m_scrollY; };
    
    private:
        float m_scrollX, m_scrollY;
    };
}
