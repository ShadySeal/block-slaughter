#pragma once

#include "event.h"

namespace bk
{
    class CursorPositionEvent : public Event
    {
    public:
        CursorPositionEvent(std::string name, float x, float y)
            : Event(name), m_posX(x), m_posY(y) {};
            
        float getPosX() const { return m_posX; };
        float getPosY() const { return m_posY; };
    
    private:
        float m_posX, m_posY;
    };
}
