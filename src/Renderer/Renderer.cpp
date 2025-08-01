#include "Renderer/Renderer.h"
#include "Event/Event.h"
#include "Event/WindowResizeEvent.h"
#include "Core/Logger/Logger.h"

namespace TRUFFLE
{
  void Renderer::Init()
  {
    RenderCommand::Init();
    EventDispatcher::GetInstance().Subscribe<WindowResizeEvent>(
        [this](const WindowResizeEvent &e)
        {
          OnWindowResize(e.GetWidth(), e.GetHeight());
        });
  }

  void Renderer::BeginFrame()
  {
    RenderCommand::SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    RenderCommand::Clear();
  }

  void Renderer::EndFrame()
  {
  }

  void Renderer::OnWindowResize(unsigned int width, unsigned int height)
  {
    RenderCommand::SetViewport(0, 0, width, height);
    LOG_DEBUG("Window resized to {}x{}", width, height);
  }
} // namespace TRUFFLE
