#pragma once

#include "event.h"

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace bk
{
    class EventPropagator
    {
    public:
        EventPropagator(Event& event)
            : m_event(event) {}

        template <std::derived_from<Event> T>
        void propagate(std::function<void(T&)> callback)
        {
            if (auto* typed = dynamic_cast<T*>(&m_event))
            {
                callback(*typed);
                m_event.m_handled = true;
            }
        }
    private:
        Event& m_event;
    };
}