#include "engine/debug/imgui_layer.h"
#include <GLFW/glfw3.h>
#include "engine/core/app.h"

namespace bk
{
    ImGuiLayer::ImGuiLayer()
    {
        
    }

    ImGuiLayer::~ImGuiLayer()
    {
        
    }

    void ImGuiLayer::onAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        ImGui_ImplOpenGL3_Init("#version 330");
    }
    void ImGuiLayer::onDetach()
    {
        
    }
    
    void ImGuiLayer::onUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();
        App& app = App::get();

        int wW = app.getWindow().getWidth();
        int wH = app.getWindow().getHeight();
        int fW = app.getWindow().getFramebufferWidth();
        int fH = app.getWindow().getFramebufferHeight();

        io.DisplaySize = ImVec2((float)wW, (float)wH);
        if (wW > 0 && wH > 0)
        {
            io.DisplayFramebufferScale = ImVec2((float)fW / (float)wW, (float)fH / (float)wH);
        }
        
        float time = (float)glfwGetTime();
        io.DeltaTime = m_time > 0.0f ? (time - m_time) : (1.0f / 60.0f);
        m_time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void ImGuiLayer::onEvent(Event& event)
    {
        EventPropagator propagator(event);

        propagator.propagate<MousePressedEvent>(BIND_EVENT_FN(ImGuiLayer::onMousePressed));
        propagator.propagate<MouseReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseReleased));
        propagator.propagate<MouseScrollEvent>(BIND_EVENT_FN(ImGuiLayer::onMouseScrolled));
        propagator.propagate<CursorPositionEvent>(BIND_EVENT_FN(ImGuiLayer::onMousePosition));

        propagator.propagate<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyPressed));
        propagator.propagate<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyReleased));
        propagator.propagate<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::onKeyRepeated));

        propagator.propagate<WindowCloseEvent>(BIND_EVENT_FN(ImGuiLayer::onWindowClosed));
        propagator.propagate<WindowResizeEvent>(BIND_EVENT_FN(ImGuiLayer::onWindowResized)); 
    }

    void ImGuiLayer::onMousePressed(MousePressedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[event.getKeyCode()] = true;
    }

    void ImGuiLayer::onMouseReleased(MouseReleasedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[event.getKeyCode()] = false;
    }

    void ImGuiLayer::onMouseScrolled(MouseScrollEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheel += event.getScrollX();
        io.MouseWheelH += event.getScrollY();
    }

    void ImGuiLayer::onMousePosition(CursorPositionEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(event.getPosX(), event.getPosY());
    }

    void ImGuiLayer::onKeyPressed(KeyPressedEvent& event)
    {
        
    }

    void ImGuiLayer::onKeyReleased(KeyReleasedEvent& event)
    {

    }

    void ImGuiLayer::onKeyRepeated(KeyPressedEvent& event)
    {

    }

    void ImGuiLayer::onWindowResized(WindowResizeEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        App& app = App::get();

        int wW = app.getWindow().getWidth();
        int wH = app.getWindow().getHeight();
        int fW = app.getWindow().getFramebufferWidth();
        int fH = app.getWindow().getFramebufferHeight();

        io.DisplaySize = ImVec2((float)wW, (float)wH);
        if (wW > 0 && wH > 0)
        {
            io.DisplayFramebufferScale = ImVec2((float)fW / (float)wW, (float)fH / (float)wH);
        }
    }

    void ImGuiLayer::onWindowClosed(WindowCloseEvent& event)
    {

    }
}
