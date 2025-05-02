#include "Core/Time/Time.h"

namespace OPENGL_TEST {
    Time::Time(std::function<float()> getter)
        : timeGetter(std::move(getter)) {}

    void Time::SetTimeGetter(std::function<float()> getter) {
        timeGetter = std::move(getter);
    }

    void Time::Init() {
        lastFrame = lastSecond = timeGetter();
    }

    void Time::Update() {
        frameCount++;

        float currentTime = timeGetter();

        if (currentTime - lastSecond >= 1.0f) {
            FPS = frameCount;
            frameCount = 0;
            lastSecond = currentTime;
        }

        deltaTime = timeScale * (currentTime - lastFrame);
        totalTime += deltaTime;
        lastFrame = currentTime;
    }
}
