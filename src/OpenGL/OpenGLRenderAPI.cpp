#include "OpenGL/OpenGLRenderAPI.h"
#include <GLFW/glfw3.h>

namespace TRUFFLE
{
  void OpenGLRenderAPI::Init()
  {
    glEnable(GL_DEPTH_TEST);
  }

  void OpenGLRenderAPI::SetClearColor(float r, float g, float b, float a)
  {
    glClearColor(r, g, b, a);
  }

  void OpenGLRenderAPI::Clear()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  void OpenGLRenderAPI::SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
  {
    glViewport(x, y, width, height);
  }
}
