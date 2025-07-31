#pragma once

#include <cstdint>
#include <cstddef>
#include <glad/glad.h>
#include "Renderer/IndexBuffer.h"

namespace TRUFFLE
{
  class OpenGLIndexBuffer : public IndexBuffer
  {
  private:
    uint32_t m_id = 0;
    size_t m_size = 0;
    uint32_t m_usage = GL_STATIC_DRAW;

  public:
    OpenGLIndexBuffer();
    OpenGLIndexBuffer(const OpenGLIndexBuffer &) = delete;
    OpenGLIndexBuffer &operator=(const OpenGLIndexBuffer &) = delete;
    ~OpenGLIndexBuffer();

    void Bind() const override;
    void Unbind() const override;
    const uint32_t &GetID() const { return m_id; }
    void SetData(const void *data, size_t size, uint32_t usage = GL_STATIC_DRAW);

  private:
    void FreeBuffer();
  };
} // namespace TRUFFLE
