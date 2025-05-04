#pragma once

namespace TRUFFLE
{
  class RenderAPI
  {
  public:
    enum class API
    {
      None = 0,
      OpenGL = 1
    };

    virtual ~RenderAPI() = default;

    virtual void Init() = 0;
    virtual void SetClearColor(float r, float g, float b, float a) = 0;
    virtual void Clear() = 0;

    inline static API GetAPI() { return s_API; }

  protected:
    static API s_API;
  };
}
