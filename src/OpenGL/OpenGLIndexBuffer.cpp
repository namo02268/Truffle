#include "OpenGL/OpenGLIndexBuffer.h"
#include "Core/Logger/Logger.h"

#include <glad/glad.h>

namespace TRUFFLE
{
  // OpenGLIndexBuffer implementation
  OpenGLIndexBuffer::OpenGLIndexBuffer()
  {
    glGenBuffers(1, &m_id);
    LOG_DEBUG("OpenGLIndexBuffer created with ID: {}", m_id);
  }

  OpenGLIndexBuffer::~OpenGLIndexBuffer()
  {
    FreeBuffer();
  }

  void OpenGLIndexBuffer::Bind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
  }

  void OpenGLIndexBuffer::Unbind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

  void OpenGLIndexBuffer::SetData(const void *data, size_t size, uint32_t usage)
  {
    m_size = size;
    m_usage = usage;
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
  }

  void OpenGLIndexBuffer::FreeBuffer()
  {
    if (m_id != 0)
    {
      glDeleteBuffers(1, &m_id);
      LOG_DEBUG("OpenGLIndexBuffer with ID {} freed", m_id);
      m_id = 0;
    }
  }
} // namespace TRUFFLE
