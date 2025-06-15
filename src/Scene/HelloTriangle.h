#pragma once

#include "Scene/Scene.h"
#include <glad/glad.h>

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
        unsigned int VBO, VAO;
        unsigned int shaderProgram;
    };
}