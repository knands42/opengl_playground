#pragma once

#include <glad/gl.h>
#include "Window.h"

namespace Core
{
    struct ApplicationSpecification
    {
        std::string Name = "Application";
        WindowSpecification WindowSpec;
    };

    class Application
    {
    public:
        Application(ApplicationSpecification spec);
        ~Application();

        void Run();
        void Stop();

        void RaiseEvent(Event& event);

        [[nodiscard]] auto GetFramebufferSize() const -> glm::vec2;

        static auto Get() -> Application&;
        static auto GetTime() -> float;
    private:
        ApplicationSpecification m_Specification;
        Window m_Window;
        bool m_Running = true;
    };
};
