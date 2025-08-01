#pragma once

#include <cstddef>
#include "Renderer/RenderCommand.h"

namespace TRUFFLE
{
  class Renderer
  {
  public:
    Renderer(unsigned int width = 800, unsigned int height = 600)
        : m_Width(width), m_Height(height) {}
    ~Renderer() = default;

    void Init();
    void BeginFrame();
    void EndFrame();
    void OnWindowResize(unsigned int width, unsigned int height);

  private:
    unsigned int m_Width;
    unsigned int m_Height;
  };
} // namespace TRUFFLE
