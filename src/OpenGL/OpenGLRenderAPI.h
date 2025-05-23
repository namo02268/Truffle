#pragma once

#include "Renderer/RenderAPI.h"

namespace TRUFFLE
{
  class OpenGLRenderAPI : public RenderAPI
  {
  public:
    virtual void Init() override;
    virtual void SetClearColor(float r, float g, float b, float a) override;
    virtual void Clear() override;
  };
} // namespace TRUFFLE
