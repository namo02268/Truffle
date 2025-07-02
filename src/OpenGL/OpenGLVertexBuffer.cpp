#include "OpenGL/OpenGLVertexBuffer.h"
#include "Core/Logger/Logger.h"

namespace TRUFFLE
{
  // OpenGLVertexBuffer implementation
  OpenGLVertexBuffer::OpenGLVertexBuffer()
  {
    glGenBuffers(1, &m_id);
    LOG_DEBUG("OpenGLVertexBuffer created with ID: {}", m_id);
  }

  OpenGLVertexBuffer::~OpenGLVertexBuffer()
  {
    FreeBuffer();
  }

  void OpenGLVertexBuffer::Bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
  }

  void OpenGLVertexBuffer::Unbind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void OpenGLVertexBuffer::SetData(const void *data, size_t size, uint32_t usage)
  {
    m_size = size;
    m_usage = usage;
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
  }

  void OpenGLVertexBuffer::FreeBuffer()
  {
    if (m_id != 0)
    {
      glDeleteBuffers(1, &m_id);
      LOG_DEBUG("OpenGLVertexBuffer with ID {} freed", m_id);
      m_id = 0;
    }
  }
} // namespace TRUFFLE
