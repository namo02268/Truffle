#pragma once

#include <cstddef>
#include <functional>

namespace TRUFFLE
{
    class Time
    {
    private:
        std::function<float()> timeGetter;

        float timeScale = 1.0f;
        float deltaTime = 0.0f;
        float totalTime = 0.0f;
        std::size_t FPS = 0;

        float lastFrame = 0.0f;
        float lastSecond = 0.0f;
        std::size_t frameCount = 0;

    public:
        explicit Time(std::function<float()> getter = nullptr);

        void Init();
        void Update();

        float GetDeltaTime() const { return deltaTime; }
        float GetTotalTime() const { return totalTime; }
        std::size_t GetFPS() const { return FPS; }

        void SetTimeGetter(std::function<float()> getter);
        void SetTimeScale(float scale) { timeScale = scale; }
    };
}
