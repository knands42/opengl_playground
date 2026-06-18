#pragma once

#include <glad/gl.h>

class VertexBuffer
{
public:
    VertexBuffer() = default;
    ~VertexBuffer();

    void Bind();
    void Unbind() const;

    [[nodiscard]] auto GetVAO() const -> unsigned int { return VAO; }
private:
    unsigned int VBO, VAO, EBO;
};
