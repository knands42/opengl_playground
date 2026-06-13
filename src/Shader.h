#pragma once

#include <sstream>
#include "glad.h"

class Shader
{
public:
    [[nodiscard]] auto GetVertexShader() const -> unsigned int { return m_VertexShader; }
    [[nodiscard]] auto GetFragmentShader() const -> unsigned int { return m_FragmentShader; }
    [[nodiscard]] auto GetShaderProgram() const -> unsigned int { return m_ShaderProgram; }

    explicit Shader(std::string  vertexPath, std::string  fragmentPath);
    ~Shader();

    auto CreateProgram() -> unsigned int;

private:
    std::string m_VertexPath;
    std::string m_FragmentPath;

    unsigned int m_ShaderProgram = 0;
    unsigned int m_VertexShader = 0;
    unsigned int m_FragmentShader = 0;


    static auto ShaderProgram(unsigned int vertexShader, unsigned int fragmentShader) -> unsigned int;
    static auto CompileShader(unsigned int type, const std::string &source) -> unsigned int;
    static auto ParseShader(const std::string &file) -> std::string;
};
