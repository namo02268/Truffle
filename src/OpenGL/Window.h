#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace TRUFFLE
{
	class Window
	{
	private:
		GLFWwindow *m_windowPtr = nullptr;
		int m_width;
		int m_height;
		const char *m_title;

	public:
		Window(int width, int height, const char *title);
		~Window();

		void BeginFrame();
		void EndFrame();

		bool IsOpen() { return !glfwWindowShouldClose(m_windowPtr); }
		GLFWwindow *GetWindowPtr() { return m_windowPtr; }
		float GetTime() const { return (float)glfwGetTime(); }

	private:
		void InitOpenGL();
		void CleanUpOpenGL();

		void InitImGUI();
		void CleanUpImGUI();
	};
}
