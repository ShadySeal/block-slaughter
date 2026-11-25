#pragma once

#include "event.h"

namespace bk
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_width(width), m_height(height) {};

        int getWidth() const { return m_width; };
        int getHeight() const { return m_height; };
    
    private:
        unsigned int m_width, m_height;
    };
}
