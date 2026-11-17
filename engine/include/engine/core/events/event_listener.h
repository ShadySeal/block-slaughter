#include "event.h"

namespace brick
{
    class IEventListener
    {
    public:
        virtual ~IEventListener() {}
        virtual void onEvent(Event event) = 0;
    };
}