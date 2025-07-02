#pragma once

namespace TRUFFLE
{
  class IndexBuffer
  {
  public:
    virtual ~IndexBuffer() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;
  };
}
