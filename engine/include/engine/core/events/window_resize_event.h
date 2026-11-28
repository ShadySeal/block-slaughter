#pragma once

#include "event.h"

namespace bk
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int width, int height)
            : m_wW(width), m_wH(height) {};

        int getWindowWidth() const { return m_wW; };
        int getWindowHeight() const { return m_wH; };

        int getFramebufferWidth() const { return m_fW; };
        int getFramebufferHeight() const { return m_fH; };
    
    private:
        int m_wW, m_wH;
        int m_fW, m_fH;
    };
}
