#pragma once

#include <deque>
#include <string>
#include "Editor/EditorPanel.h"

namespace TRUFFLE
{
  class Console : public EditorPanel
  {
  public:
    Console() = default;
    ~Console() = default;

    void Init() override;
    void Render() override;
    void PushLog(const std::string &logMessage);
    void Clear();

  private:
    std::deque<std::string> m_logBuffer;
    const size_t m_maxBufferSize = 1000;
  };
} // namespace TRUFFLE
