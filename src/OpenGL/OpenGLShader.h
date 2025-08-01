#pragma once

#include <cstdint>
#include <glad/glad.h>
#include "Renderer/Shader.h"

namespace TRUFFLE
{
  class OpenGLShader : public Shader
  {
  private:
    uint32_t m_id = 0;

  public:
    OpenGLShader();
    ~OpenGLShader();

    void Bind() const override;
    void Unbind() const override;

    bool Load(const std::string &vertexSrc, const std::string &fragmentSrc) override;

  private:
    void FreeShader();

    GLuint CompileShader(GLenum type, const std::string &source);
  };

} // namespace TRUFFLE
