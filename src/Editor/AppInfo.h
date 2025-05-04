#pragma once

#include "Editor/EditorPanel.h"

namespace TRUFFLE
{
  class AppInfo : public EditorPanel
  {
  public:
    AppInfo() = default;
    ~AppInfo() = default;

    void Init() override;
    void Render() override;
  };
} // namespace TRUFFLE
