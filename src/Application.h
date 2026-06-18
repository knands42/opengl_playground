#pragma once

#include <glad/gl.h>
#include "GLFW/glfw3.h"
#include "Shader.h"
#include "VertexBuffer.h"

constexpr unsigned int DEFAULT_WIDTH = 800;
constexpr unsigned int DEFAULT_HEIGHT = 600;

class Application
{
public:
    Application();
    ~Application();

    auto run(unsigned int get_shader_program, unsigned int get_vao) -> void;
private:
    unsigned int width = DEFAULT_WIDTH, height = DEFAULT_HEIGHT;
    GLFWwindow *window = nullptr;
    unsigned int m_VAO;
    unsigned int m_shaderProgram;

    void mainLoop() const;

    // glfw: whenever the window size changed (by OS or user resize) this callback
    // function executes
    // ---------------------------------------------------------------------------------------------
    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    // process all input: query GLFW whether relevant keys are pressed/released this
    // frame and react accordingly
    // ---------------------------------------------------------------------------------------------------------
    static void processInput(GLFWwindow *window);
};
