namespace engine
{
    enum class EventType
    {
        WINDOW_RESIZE,
        WINDOW_CLOSE,
        KEY_PRESSED,
        MOUSE_MOVED
    };

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