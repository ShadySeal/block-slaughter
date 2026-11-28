#pragma once

#include "engine/core/layer.h"
#include <backends/imgui_impl_opengl3.h>
#include "engine/core/events/event_propagator.h"
#include "engine/core/events/window_resize_event.h"
#include "engine/core/events/window_close_event.h"
#include "engine/core/events/mouse_scroll_event.h"
#include "engine/core/events/cursor_position_event.h"
#include "engine/core/events/key_pressed_event.h"
#include "engine/core/events/key_released_event.h"
#include "engine/core/events/mouse_pressed_event.h"
#include "engine/core/events/mouse_released_event.h"

namespace bk
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void onAttach() override;
        void onDetach() override;
        void onUpdate() override;
        void onEvent(Event& event) override;

    private:
        float m_time = 0.0f;

        void onMousePressed(MousePressedEvent& event);
        void onMouseReleased(MouseReleasedEvent& event);
        void onMouseScrolled(MouseScrollEvent& event);
        void onMousePosition(CursorPositionEvent& event);
        void onKeyPressed(KeyPressedEvent& event);
        void onKeyReleased(KeyReleasedEvent& event);
        void onKeyRepeated(KeyPressedEvent& event);
        void onWindowResized(WindowResizeEvent& event);
        void onWindowClosed(WindowCloseEvent& event);
    };
}
