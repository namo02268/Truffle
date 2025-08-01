#include "OpenGL/OpenGLWindow.h"
#include "Event/Event.h"
#include "Event/WindowResizeEvent.h"

namespace TRUFFLE
{
	OpenGLWindow::OpenGLWindow(const WindowProps &props)
	{
		Init(props);
	}

	OpenGLWindow::~OpenGLWindow()
	{
		Shutdown();
	}

	void OpenGLWindow::Init(const WindowProps &props)
	{
		m_data.Title = props.Title;
		m_data.Width = props.Width;
		m_data.Height = props.Height;

		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		m_windowPtr = glfwCreateWindow(m_data.Width, m_data.Height, m_data.Title.c_str(), nullptr, nullptr);
		if (!m_windowPtr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_windowPtr);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return;
		}

		glfwSetWindowSizeCallback(m_windowPtr, [](GLFWwindow *window, int width, int height)
															{
        auto* win = reinterpret_cast<OpenGLWindow*>(glfwGetWindowUserPointer(window));
        if (win)
        {
            win->m_data.Width = width;
            win->m_data.Height = height;

            // イベントを発行
            WindowResizeEvent event(width, height);
            EventDispatcher::GetInstance().Dispatch(event);
        } });

		glfwSetWindowUserPointer(m_windowPtr, this);

		SetVSync(true);
	}

	void OpenGLWindow::Shutdown()
	{
		glfwDestroyWindow(m_windowPtr);
		glfwTerminate();
	}

	void OpenGLWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_windowPtr);
	}

	void OpenGLWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
		m_data.VSync = enabled;
	}
}
