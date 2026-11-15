#include "event.h"

namespace engine
{
    class IEventListener
    {
    public:
        virtual ~IEventListener() {}
        virtual void onEvent(Event event) = 0;
    };
}