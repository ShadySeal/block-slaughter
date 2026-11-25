#pragma once

#include "event.h"

namespace bk
{
    // This class is similar to EventPropagator, but is subscription based and can hold multiple events in a list (similar to C# events).
    // The plan is to use this class to handle some in-game code.
    // TODO: Remove name requirement and make m_handlers a vector.

    class EventDispatcher
    {
    public:
        template <std::derived_from<Event> T>
        void subscribe(const std::string& name, std::function<void(T&)> callback)
        {
            m_handlers[name].push_back([callback](Event& event)
            {
                if (auto* typed = dynamic_cast<T*>(&event))
                {
                    callback(*typed);
                }
            });
        }

        void dispatch(Event& event);

    private:
        std::unordered_map<std::string, std::vector<std::function<void(Event&)>>> m_handlers;
    };
}
