#pragma once

#include "GLFW/glfw3.h"
#include "glad.h"

class Application
{
public:
    auto run() -> int;

private:
    unsigned int width = 800, height = 600;
    GLFWwindow *window = nullptr;

    void mainLoop();

    // glfw: whenever the window size changed (by OS or user resize) this callback
    // function executes
    // ---------------------------------------------------------------------------------------------
    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    // process all input: query GLFW whether relevant keys are pressed/released this
    // frame and react accordingly
    // ---------------------------------------------------------------------------------------------------------
    static void processInput(GLFWwindow *window);
};
