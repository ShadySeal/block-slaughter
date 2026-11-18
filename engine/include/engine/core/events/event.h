#pragma once

#include "event_type.h"

namespace bk
{
    struct Event
    {
        Event(EventType type) : type(type) {};

        EventType type;
        union
        {
            struct { int width, height; } resize;
            struct { int key; } key;
            struct { double x, y; } mouse;
            struct { double x, y; } scroll;
        };
    };
}
