#pragma once

#include <string>

namespace TRUFFLE
{
  class Shader
  {
  public:
    virtual ~Shader() = default;

    virtual bool Load(const std::string &vertexSrc, const std::string &fragmentSrc) = 0;
    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    // TODO: Implement uniform setters
  };
} // namespace TRUFFLE
