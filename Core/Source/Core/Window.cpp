#include "Window.h"

#include <utility>
#include <print>
#include <cassert>

#include "WindowEvents.h"
#include "Event.h"
#include "InputEvents.h"

namespace Core
{
    Window::Window(WindowSpecification spec) : m_Specification(std::move(spec))
    {
    }

    Window::~Window()
    {
        Destroy();
    }

    void Window::Create()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        m_Window = glfwCreateWindow(m_Specification.Width, m_Specification.Height, m_Specification.Title.c_str(),
                                    nullptr, nullptr);

        if (!m_Window)
        {
            std::println("Failed to create GLFW window!");
            assert(false);
        }

        glfwMakeContextCurrent(m_Window);
        // TODO: Check if needed
        // glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
        gladLoadGL(glfwGetProcAddress);
        glfwSwapInterval(m_Specification.VSync ? 1 : 0);
        glfwSetWindowUserPointer(m_Window, this);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *glfwWindow)
                               -> void
                                   {
                                       // TODO: Understand how is this conversion working
                                       Window &window = *(static_cast<Window *>(glfwGetWindowUserPointer(glfwWindow)));

                                       WindowClosedEvent event;
                                       window.RaiseEvent(event);
                                   });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *glfwWindow, int width, int height)
                              -> void
                                  {
                                      Window &window = *(static_cast<Window *>(glfwGetWindowUserPointer(glfwWindow)));

                                      WindowResizeEvent event(static_cast<uint32_t>(width),
                                                              static_cast<uint32_t>(height));
                                      window.RaiseEvent(event);
                                  });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *handle, const int key, int scancode, const int action, int mods)
                       -> void
                           {
                               Window &window = *(static_cast<Window *>(glfwGetWindowUserPointer(handle)));

                               switch (action)
                               {
                                   case GLFW_PRESS:
                                   case GLFW_REPEAT: {
                                       KeyPressedEvent event(key, action == GLFW_REPEAT);
                                       window.RaiseEvent(event);
                                       break;
                                   }
                                   case GLFW_RELEASE: {
                                       KeyReleasedEvent event(key);
                                       window.RaiseEvent(event);
                                       break;
                                   }
                               }
                           });
    }

    void Window::Destroy()
    {
        if (m_Window) glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }

    void Window::Update()
    {
        glfwSwapBuffers(m_Window);
    }

    void Window::RaiseEvent(Event &event)
    {
        if (m_Specification.EventCallback)
        {
            m_Specification.EventCallback(event);
        }
    }

    auto Window::GetFramebufferSize() const -> glm::vec2
    {
        int width, height;
        glfwGetFramebufferSize(m_Window, &width, &height);
        return {static_cast<float>(width), static_cast<float>(height)};
    }

    auto Window::GetMousePos() const -> glm::vec2
    {
        double x, y;
        glfwGetCursorPos(m_Window, &x, &y);
        return {static_cast<float>(x), static_cast<float>(y)};
    }

    auto Window::ShouldClose() const -> bool
    {
        return glfwWindowShouldClose(m_Window);
    }

    void FramebufferSizeCallback(GLFWwindow *window, const int width, const int height)
    {
        glViewport(0, 0, width, height);
    }
}
