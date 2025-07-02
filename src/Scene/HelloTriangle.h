#pragma once

#include "Scene/Scene.h"
#include "OpenGL/OpenGLVertexBuffer.h"
#include "OpenGL/OpenGLIndexBuffer.h"
#include "OpenGL/OpenGLVertexArray.h"

namespace TRUFFLE
{
    class HelloTriangle : public Scene
    {
    public:
        void OnInit() override;
        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnShutdown() override;

    private:
        OpenGLVertexArray VAO;
        OpenGLVertexBuffer VBO;
        OpenGLIndexBuffer IBO;
        unsigned int shaderProgram;
    };
}
