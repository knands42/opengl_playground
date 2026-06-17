#include "Application.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cassert>
#include <print>

namespace Core
{
    static Application* s_Application = nullptr;

    static void GLFWErrorCallback(int error, const char* description)
    {
        std::println("GLFW Error: {0}", description);
    }

    Application::Application(ApplicationSpecification spec) : m_Specification(std::move(spec))
    {
        s_Application = this;

        glfwSetErrorCallback(GLFWErrorCallback);
        glfwInit();

        // Set window title to app name if empty
        if (m_Specification.WindowSpec.Title.empty())
            m_Specification.WindowSpec.Title = m_Specification.Name;

        m_Specification.WindowSpec.EventCallback = [this](Event& event) -> void { RaiseEvent(event); };

        m_Window = std::make_shared<Window>(m_Specification.WindowSpec);
        m_Window.Create();
    }

    Application::~Application()
    {
        m_Window.Destroy();
        glfwTerminate();
        s_Application = nullptr;
    }

    void Application::Run()
    {
        m_Running = true;

        float lastTime = GetTime();

        while (m_Running)
        {

        }
    }

    void Application::Stop()
    {
        m_Running = false;
    }


    void Application::RaiseEvent(Event& event)
    {

    }

    auto Application::GetFramebufferSize() const -> glm::vec2
    {
        return m_Window.GetFramebufferSize();
    }

    auto Application::Get() -> Application&
    {
        assert(s_Application);
        return *s_Application;
    }

    auto Application::GetTime() -> float
    {
        return static_cast<float>(glfwGetTime());
    }

};
