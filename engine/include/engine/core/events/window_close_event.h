#pragma once

#include "event.h"

namespace bk
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent(std::string name)
            : Event(name) {};
    };
}
