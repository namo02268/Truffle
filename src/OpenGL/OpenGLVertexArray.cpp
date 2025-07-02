#include "OpenGL/OpenGLVertexArray.h"
#include "Core/Logger/Logger.h"

namespace TRUFFLE
{
  OpenGLVertexArray::OpenGLVertexArray()
  {
    glGenVertexArrays(1, &m_id);
    LOG_DEBUG("OpenGLVertexArray created with ID: {}", m_id);
  }

  OpenGLVertexArray::~OpenGLVertexArray()
  {
    FreeVertexArray();
  }

  void OpenGLVertexArray::Bind() const
  {
    glBindVertexArray(m_id);
  }

  void OpenGLVertexArray::Unbind() const
  {
    glBindVertexArray(0);
  }

  void OpenGLVertexArray::clear()
  {
    m_attributeIndex = 0;
    m_stride = 0;
  }

  void OpenGLVertexArray::PushImpl(const std::type_info &type, uint32_t count, bool normalized)
  {
    GLenum glType = 0;
    GLsizei typeSize = 0;

    if (type == typeid(float))
    {
      glType = GL_FLOAT;
      typeSize = sizeof(float);
    }
    else if (type == typeid(unsigned int))
    {
      glType = GL_UNSIGNED_INT;
      typeSize = sizeof(unsigned int);
    }
    else if (type == typeid(unsigned char))
    {
      glType = GL_UNSIGNED_BYTE;
      typeSize = sizeof(unsigned char);
    }
    else
    {
      LOG_DEBUG("Unsupported attribute type for VertexArray");
      return;
    }

    glEnableVertexAttribArray(m_attributeIndex);
    glVertexAttribPointer(m_attributeIndex, count, glType, normalized ? GL_TRUE : GL_FALSE, m_stride, (const void *)0);
    m_attributeIndex++;
    m_stride += typeSize * count;
  }

  void OpenGLVertexArray::FreeVertexArray()
  {
    if (m_id != 0)
    {
      glDeleteVertexArrays(1, &m_id);
      LOG_DEBUG("OpenGLVertexArray with ID {} freed", m_id);
      m_id = 0;
    }
  }
} // namespace TRUFFLE
