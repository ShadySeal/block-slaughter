#include "event_listener.h"
#include <vector>

namespace engine
{
    class EventDispatcher
    {
    public:
        void subcribe(IEventListener* listener);
        void unsubscribe(IEventListener* listener);

    private:
        std::vector<IEventListener*> _listeners;

    protected:
        void dispatch(Event event);
    };

}