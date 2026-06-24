#pragma once

#include <cstdio>

#include "glad/gl.h"

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char *function, const char *file, int line)
{
    while (GLenum error = glGetError())
    {
        printf("[OpenGL error] (%d) at function (%s) at file (%s) at line (%d)",
                   error, function, file, line);
        return false;
    }

    return true;
}
