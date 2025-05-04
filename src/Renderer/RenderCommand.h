#pragma once

#include "Renderer/RenderAPI.h"
#include "OpenGL/OpenGLRenderAPI.h"

namespace TRUFFLE
{
  class RenderCommand
  {
  public:
    static void Init()
    {
      s_RenderAPI->Init();
    }

    static void SetClearColor(float r, float g, float b, float a)
    {
      s_RenderAPI->SetClearColor(r, g, b, a);
    }

    static void Clear()
    {
      s_RenderAPI->Clear();
    }

  private:
    static inline RenderAPI *s_RenderAPI = new OpenGLRenderAPI();
  };
}
