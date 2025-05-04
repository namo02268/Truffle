#pragma once

namespace TRUFFLE
{
  class EditorPanel
  {
  public:
    EditorPanel() = default;
    virtual ~EditorPanel() = default;

    virtual void Init() = 0;
    virtual void Render() = 0;
  };
} // namespace TRUFFLE
