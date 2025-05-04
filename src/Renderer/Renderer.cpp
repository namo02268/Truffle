#include "Renderer/Renderer.h"

namespace TRUFFLE
{
  void Renderer::Init()
  {
    RenderCommand::Init();
  }

  void Renderer::BeginFrame()
  {
    RenderCommand::SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    RenderCommand::Clear();
  }

  void Renderer::EndFrame()
  {
  }
} // namespace TRUFFLE
