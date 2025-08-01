#include "Scene/HelloTriangle.h"
#include "Core/Logger/Logger.h"

namespace TRUFFLE
{
    void HelloTriangle::OnInit()
    {
        LOG_INFO("HelloTriangle initialized.");

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        VAO.Bind();
        VBO.SetData(vertices, sizeof(vertices));
        VAO.Push<float>(3, false);
        VAO.Unbind();

        const char *vertexShaderSource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                         "}\0";
        const char *fragmentShaderSource = "#version 330 core\n"
                                           "out vec4 FragColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                           "}\n\0";

        shader.Load(vertexShaderSource, fragmentShaderSource);
    }

    void HelloTriangle::OnUpdate(float deltaTime)
    {
    }

    void HelloTriangle::OnRender()
    {
        shader.Bind();
        VAO.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void HelloTriangle::OnShutdown()
    {
    }
}
