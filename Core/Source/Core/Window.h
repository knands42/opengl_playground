#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Event.h"
#include "glm/glm.hpp"

#include <functional>

namespace Core
{
    struct WindowSpecification
    {
        std::string Title;
        uint32_t Width = 1280;
        uint32_t Height = 720;
        bool IsResizeable = true;
        bool VSync = true;

        using EventCallbackFn = std::function<void>(Event*);
        EventCallbackFn EventCallback;
    };

    class Window
    {
    public:
        Window(WindowSpecification spec = WindowSpecification());
        ~Window();

        void Create();
        void Destroy();

        void Update();
        void RaiseEvent(Event& event);

        glm::vec2 GetFramebufferSize() const;
        glm::vec2 GetMousePos() const;

        bool ShouldClose() const;

        GLFWwindow* GetWindow() const { return m_Window; }

    private:
        WindowSpecification m_Specification;
        GLFWwindow* m_Window = nullptr;
    };
}
