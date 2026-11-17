#include "event_listener.h"

namespace brick
{
    class EventDispatcher
    {
    public:
        void subcribe(IEventListener* listener);
        void unsubscribe(IEventListener* listener);

    private:
        std::vector<IEventListener*> m_listeners;

    protected:
        void dispatch(Event event);
    };

}