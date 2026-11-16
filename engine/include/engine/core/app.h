#pragma once

#include <memory>

#include "engine/core/window.h"

namespace engine
{
    class App
    {
    public:
        App();
        ~App();

        void run();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running;
    };
}
