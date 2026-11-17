#pragma once

#include "event_type.h"

namespace brick
{
    struct Event
    {
        EventType type;
        union
        {
            struct { int width, height; } resize;
            struct { int key; } key;
            struct { double x, y; } mouse;
        };
    };
}
