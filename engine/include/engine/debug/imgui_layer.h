#pragma once

#include "engine/core/layer.h"

namespace bk
{
    class ImGuiLayer : public Layer
    {
    public:
        void onAttach() override;
        void onDetach() override;
        void onUpdate() override;
    };
}
