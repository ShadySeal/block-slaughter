#include "engine/core/events/event_dispatcher.h"
#include "engine/core/log.h"

namespace engine
{
    void EventDispatcher::subcribe(IEventListener* listener)
    {
        if (listener == nullptr)
        {
            LOG_CORE_ERROR("Cannot add listener: null.");
            return;
        }

        _listeners.push_back(listener);
    }

    void EventDispatcher::unsubscribe(IEventListener* listener)
    {
        if (listener == nullptr)
        {
            LOG_CORE_ERROR("Cannot remove listener: null.");
            return;
        }

        std::erase(_listeners, listener);
    }

    void EventDispatcher::dispatch(Event event)
    {
        for (int i = 0; i < _listeners.size(); i++)
        {
            _listeners[i]->onEvent(event);
        }
    }
}