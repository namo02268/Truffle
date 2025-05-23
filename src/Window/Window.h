#pragma once

#include <string>

namespace TRUFFLE
{
  struct WindowProps
  {
    std::string Title;
    unsigned int Width;
    unsigned int Height;

    WindowProps(const std::string &title = "Truffle Engine",
                unsigned int width = 1280,
                unsigned int height = 720)
        : Title(title), Width(width), Height(height) {}
  };

  class Window
  {
  public:
    virtual ~Window() = default;

    virtual void OnUpdate() = 0;

    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    virtual void *GetNativeWindow() const = 0;

    virtual void SetVSync(bool enabled) = 0;
    virtual bool IsVSync() const = 0;

    virtual float GetTime() const = 0;
    virtual bool IsOpen() const = 0;
  };
}
