#include "OpenGL/OpenGLShader.h"
#include "Core/Logger/Logger.h"

namespace TRUFFLE
{
  OpenGLShader::OpenGLShader()
  {
    m_id = glCreateProgram();
    LOG_DEBUG("OpenGLShader created with ID: {}", m_id);
  }

  OpenGLShader::~OpenGLShader()
  {
    FreeShader();
  }

  void OpenGLShader::Bind() const
  {
    glUseProgram(m_id);
  }

  void OpenGLShader::Unbind() const
  {
    glUseProgram(0);
  }

  bool OpenGLShader::Load(const std::string &vertexSrc, const std::string &fragmentSrc)
  {
    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSrc);
    if (vertexShader == 0)
    {
      LOG_ERROR("Failed to compile vertex shader");
      return false;
    }

    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);
    if (fragmentShader == 0)
    {
      LOG_ERROR("Failed to compile fragment shader");
      glDeleteShader(vertexShader);
      return false;
    }

    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragmentShader);
    glLinkProgram(m_id);

    GLint isLinked = 0;
    glGetProgramiv(m_id, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &maxLength);

      std::string infoLog(maxLength, ' ');
      glGetProgramInfoLog(m_id, maxLength, &maxLength, &infoLog[0]);

      LOG_ERROR("Shader program linking failed: {}", infoLog);
      FreeShader();

      glDeleteShader(vertexShader);
      glDeleteShader(fragmentShader);
      return false;
    }

    // シェーダーオブジェクトは不要になったら削除
    glDetachShader(m_id, vertexShader);
    glDetachShader(m_id, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
  }

  GLuint OpenGLShader::CompileShader(GLenum type, const std::string &source)
  {
    GLuint shader = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint isCompiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

      std::string infoLog(maxLength, ' ');
      glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
      LOG_ERROR("Shader compilation failed: {}", infoLog);

      glDeleteShader(shader);
      return 0;
    }
    return shader;
  }

  void OpenGLShader::FreeShader()
  {
    if (m_id != 0)
    {
      glDeleteProgram(m_id);
      m_id = 0;
    }
  }
}
