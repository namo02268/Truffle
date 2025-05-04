#pragma once

#include "Renderer/RenderCommand.h"

namespace TRUFFLE
{
  class Renderer
  {
  public:
    void Init();
    void BeginFrame();
    void EndFrame();
  };
} // namespace TRUFFLE
