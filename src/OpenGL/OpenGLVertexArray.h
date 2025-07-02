#pragma once

#include "Renderer/VertexArray.h"
#include <glad/glad.h>

namespace TRUFFLE
{
  class OpenGLVertexArray : public VertexArray
  {
  private:
    uint32_t m_id = 0;
    uint32_t m_attributeIndex = 0;
    size_t m_stride = 0;

  public:
    OpenGLVertexArray();
    OpenGLVertexArray(const OpenGLVertexArray &) = delete;
    OpenGLVertexArray &operator=(const OpenGLVertexArray &) = delete;
    ~OpenGLVertexArray();

    void Bind() const override;
    void Unbind() const override;
    void clear() override;

  protected:
    void PushImpl(const std::type_info &type, uint32_t count, bool normalized) override;

  private:
    void FreeVertexArray();
  };
} // namespace TRUFFLE
