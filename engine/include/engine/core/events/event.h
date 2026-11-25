#pragma once

namespace bk
{
    class Event
    {
        friend class EventPropagator;

    public:
        virtual ~Event() = default;

    private:
        bool m_handled = false;
    };
}
