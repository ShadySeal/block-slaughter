#include "engine/core/events/event_dispatcher.h"
namespace bk
{
    void EventDispatcher::dispatch(Event& event)
    {
        for (auto& handler : m_handlers)
        {
            handler(event);
        }
    }
}