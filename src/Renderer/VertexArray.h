#pragma once

#include <cstdint>
#include <typeinfo>
#include <cstddef>

namespace TRUFFLE
{
  class VertexArray
  {
  public:
    virtual ~VertexArray() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;
    virtual void clear() = 0;

    template <typename T>
    void Push(uint32_t count, bool normalized = false)
    {
      PushImpl(typeid(T), count, normalized);
    }

  protected:
    virtual void PushImpl(const std::type_info &type, uint32_t count, bool normalized) = 0;
  };
}
