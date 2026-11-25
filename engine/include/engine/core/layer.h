#pragma once

#include "events/event.h"

namespace bk
{
    class Layer
    {
    public:
        Layer();
        virtual ~Layer();

        virtual void onAttach();
        virtual void onDetach();
        virtual void onUpdate();
        virtual void onEvent(Event& event);
    };
}
