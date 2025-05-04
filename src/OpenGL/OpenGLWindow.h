#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window/Window.h"

namespace TRUFFLE
{
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(const WindowProps &props);
		virtual ~OpenGLWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_data.Width; }
		inline unsigned int GetHeight() const override { return m_data.Height; }

		inline void *GetNativeWindow() const override { return m_windowPtr; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return m_data.VSync; }

		inline float GetTime() const override { return static_cast<float>(glfwGetTime()); }
		inline bool IsOpen() const override { return !glfwWindowShouldClose(m_windowPtr); }

	private:
		virtual void Init(const WindowProps &props);
		virtual void Shutdown();

	private:
		GLFWwindow *m_windowPtr;
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
		};
		WindowData m_data;
	};
}
