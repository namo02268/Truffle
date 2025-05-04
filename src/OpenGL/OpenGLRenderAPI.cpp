#include "OpenGL/OpenGLRenderAPI.h"
#include <glfw/glfw3.h>

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
}
