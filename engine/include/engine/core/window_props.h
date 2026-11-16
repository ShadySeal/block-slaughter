#pragma once

#include "window_mode.h"

namespace engine
{
    struct WindowProps
    {
        unsigned int width, height;
        const char* title;
        WindowMode mode;

        WindowProps(unsigned int width = 1280,
            unsigned int height = 720,
            const char* title = "Block Slaughter",
            WindowMode mode = WindowMode::WINDOWED)
            : width(width), height(height), title(title), mode(mode) {};
    };
}