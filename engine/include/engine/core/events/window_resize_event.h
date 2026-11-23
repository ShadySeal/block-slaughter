#pragma once

#include "event.h"

namespace bk
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(std::string name, unsigned int width, unsigned int height)
            : Event(name), m_width(width), m_height(height) {};

        int getWidth() const { return m_width; };
        int getHeight() const { return m_height; };
    
    private:
        unsigned int m_width, m_height;
    };
}
