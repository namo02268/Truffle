#pragma once

#include "Renderer/RenderAPI.h"
#include "OpenGL/OpenGLRenderAPI.h"

namespace TRUFFLE
{
  class RenderCommand
  {
  public:
    inline static void Init()
    {
      s_RenderAPI->Init();
    }

    inline static void SetClearColor(float r, float g, float b, float a)
    {
      s_RenderAPI->SetClearColor(r, g, b, a);
    }

    inline static void Clear()
    {
      s_RenderAPI->Clear();
    }

    inline static void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
    {
      s_RenderAPI->SetViewport(x, y, width, height);
    }

  private:
    static inline RenderAPI *s_RenderAPI = new OpenGLRenderAPI();
  };
}
