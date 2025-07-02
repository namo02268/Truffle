#pragma once

#include <cstdint>
#include <glad/glad.h>
#include "Renderer/VertexBuffer.h"

namespace TRUFFLE
{
  class OpenGLVertexBuffer : public VertexBuffer
  {
  private:
    uint32_t m_id = 0;
    size_t m_size = 0;
    uint32_t m_usage = 0;

  public:
    OpenGLVertexBuffer();
    OpenGLVertexBuffer(const OpenGLVertexBuffer &) = delete;
    OpenGLVertexBuffer &operator=(const OpenGLVertexBuffer &) = delete;
    ~OpenGLVertexBuffer();

    void Bind() const override;
    void Unbind() const override;
    const uint32_t &GetID() const { return m_id; }
    void SetData(const void *data, size_t size, uint32_t usage = GL_STATIC_DRAW);

  private:
    void FreeBuffer();
  };
} // namespace TRUFFLE
