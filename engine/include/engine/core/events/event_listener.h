#pragma once

#include "event.h"

namespace bk
{
    class IEventListener
    {
    public:
        virtual ~IEventListener() {}
        virtual void onEvent(Event event) = 0;
    };
}