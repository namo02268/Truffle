#include "OpenGL/Window.h"

namespace TRUFFLE
{
	Window::Window(int width, int height, const char *title)
	{
		m_width = width;
		m_height = height;
		m_title = title;

		this->InitOpenGL();
	}

	Window::~Window()
	{
		this->CleanUpOpenGL();
	}

	void Window::BeginFrame()
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::EndFrame()
	{
		glfwSwapBuffers(m_windowPtr);
		glfwPollEvents();
	}

	void Window::InitOpenGL()
	{
		// initialize GLFW
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		// create GLFW window
		m_windowPtr = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (m_windowPtr == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			this->CleanUpOpenGL();
		}
		glfwMakeContextCurrent(m_windowPtr);

		// initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}

		// OpenGL configuration
		glEnable(GL_DEPTH_TEST);
		glfwSwapInterval(1);
	}

	void Window::CleanUpOpenGL()
	{
		glfwTerminate();
	}
}
