#include "Editor/Console.h"
#include "Core/Logger/Logger.h"
#include "imgui/imgui.h"

namespace TRUFFLE
{
  void Console::Init()
  {
    LOGGER().RegisterCallback([this](const std::string &msg)
                              { PushLog(msg); });
  }

  void Console::PushLog(const std::string &logMessage)
  {
    if (m_logBuffer.size() >= m_maxBufferSize)
      m_logBuffer.pop_front();
    m_logBuffer.push_back(logMessage);
  }

  void Console::Clear()
  {
    m_logBuffer.clear();
  }

  void Console::Render()
  {
    ImGui::Begin("Logger");

    if (ImGui::Button("Clear"))
      Clear();
    ImGui::Separator();

    for (const auto &line : m_logBuffer)
    {
      ImGui::TextUnformatted(line.c_str());
    }

    ImGui::End();
  }
} // namespace TRUFFLE
