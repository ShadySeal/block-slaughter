#pragma once

#include "event.h"

namespace bk
{
    class EventDispatcher
    {
    public:
        template <std::derived_from<Event> T>
        void subscribe(std::function<void(T&)> callback)
        {
            m_handlers.push_back([callback](Event& event)
            {
                if (auto* typed = dynamic_cast<T*>(&event))
                {
                    callback(*typed);
                }
            });
        }

        void dispatch(Event& event);

    private:
        std::vector<std::function<void(Event&)>> m_handlers;
    };
}
