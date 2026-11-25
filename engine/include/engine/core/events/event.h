#pragma once

namespace bk
{
    class Event
    {
        friend class EventPropagator;

    public:
        virtual ~Event() = default;

        bool isHandled() { return m_handled; };

    private:
        bool m_handled = false;
    };
}
