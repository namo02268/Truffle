#pragma once

namespace TRUFFLE
{
    class Scene
    {
    public:
        virtual ~Scene() = default;

        virtual void OnInit() {}
        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
        virtual void OnShutdown() {}
    };    
}