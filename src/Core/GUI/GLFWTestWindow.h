#pragma once

#include "Core/Application/Application.h"
#include "imgui/imgui.h"

namespace TRUFFLE
{
  void ApplicationInfo()
  {
    auto &app = Application::GetInstance();
    ImGui::Begin("Application Info", nullptr);
    if (ImGui::TreeNode("Time"))
    {
      ImGui::Text("Delta Time : %f", app.GetDeltaTime());
      ImGui::Text("FPS : %d", app.GetFPS());
      ImGui::Text("Total Time : %4.2f", app.GetTotalTime());
      ImGui::TreePop();
    }

    if (ImGui::TreeNode("OpenGL Info"))
    {
      auto windowPtr = app.GetWindow()->GetWindowPtr();
      ImGui::Text("GLFW_FOCUSED : %d", glfwGetWindowAttrib(windowPtr, GLFW_FOCUSED));
      ImGui::Text("GLFW_CONTEXT_VERSION_MAJOR : %d", glfwGetWindowAttrib(windowPtr, GLFW_CONTEXT_VERSION_MAJOR));
      ImGui::Text("GLFW_CONTEXT_VERSION_MINOR : %d", glfwGetWindowAttrib(windowPtr, GLFW_CONTEXT_VERSION_MINOR));
      ImGui::TreePop();
    }

    ImGui::End();
  }
}
