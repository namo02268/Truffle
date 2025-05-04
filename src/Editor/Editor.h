#pragma once

#include <vector>
#include <memory>
#include <GLFW/glfw3.h>
#include "Editor/EditorPanel.h"

namespace TRUFFLE
{
  class Editor
  {
  public:
    Editor() = default;
    ~Editor() = default;

    void Init(GLFWwindow *windowPtr);
    void Render();
    void Shutdown();

  private:
    void BeginFrame();
    void EndFrame();
    void InitDockSpace();

    std::vector<std::unique_ptr<EditorPanel>> m_panels;
  };
} // namespace TRUFFLE
