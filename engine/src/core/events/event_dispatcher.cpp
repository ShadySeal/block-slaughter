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

        m_listeners.push_back(listener);
    }

    void EventDispatcher::unsubscribe(IEventListener* listener)
    {
        if (listener == nullptr)
        {
            LOG_CORE_ERROR("Cannot remove listener: null.");
            return;
        }

        std::erase(m_listeners, listener);
    }

    void EventDispatcher::dispatch(Event event)
    {
        for (int i = 0; i < m_listeners.size(); i++)
        {
            m_listeners[i]->onEvent(event);
        }
    }
}