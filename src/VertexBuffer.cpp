#include "VertexBuffer.h"

#include <vector>

void VertexBuffer::Init(const float *vertices, const unsigned int vertexSize,
              const unsigned int *indices, const unsigned int indexSize)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertices, GL_STATIC_DRAW);

    if (indices && indexSize > 0)
    {
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, indices, GL_STATIC_DRAW);
        indexCount = indexSize / sizeof(unsigned int);
        useIndices = true;
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

VertexBuffer::~VertexBuffer()
{
    Unbind();
}

auto VertexBuffer::Bind() const -> void
{
    glBindVertexArray(VAO);
}

auto VertexBuffer::Draw() const -> void
{
    if (useIndices) {
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, 3); // adjust vertex count to match your data
    }
}

auto VertexBuffer::EnablePolygonMode() const -> void
{
    // wireframe polygons
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

auto VertexBuffer::Unbind() -> void
{
    if (VAO) { glDeleteVertexArrays(1, &VAO); VAO = 0; }
    if (VBO) { glDeleteBuffers(1, &VBO); VBO = 0; }
    if (EBO) { glDeleteBuffers(1, &EBO); EBO = 0; }

    glBindVertexArray(0);
}
