#pragma once

namespace TRUFFLE
{
  class VertexBuffer
  {
  public:
    virtual ~VertexBuffer() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;
  };
}
