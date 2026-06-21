#pragma once

#include <glad/gl.h>

class VertexBuffer
{
public:
    ~VertexBuffer();

    void Init(const float *vertices, unsigned int vertexSize,
              const unsigned int *indices, unsigned int indexSize);

    void Bind() const;
    void Unbind();
    void Draw() const;
    void EnablePolygonMode() const;

    [[nodiscard]] auto GetVAO() const -> unsigned int { return VAO; }

private:
    unsigned int VBO, VAO, EBO;
    unsigned int indexCount = 0;
    bool useIndices = false;
};
