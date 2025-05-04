#include "Core/Application/Application.h"

#include "Editor/GLFWTestWindow.h"
#include "Core/Logger/Logger.h"

namespace TRUFFLE
{
	Application::Application()
	{
		m_window = std::make_unique<Window>(1200, 800, "Truffle Engine");
		m_time = std::make_unique<Time>([this]()
																		{ return m_window->GetTime(); });
		m_editor = std::make_unique<Editor>();

		LOGGER().SetLogLevel(LogLevel::DEBUG);
		LOGGER().RegisterCallback([](const std::string &msg)
															{ std::cout << msg << std::endl; });
		LOG_INFO("Application started.");
	}

	Application::~Application()
	{
		Shutdown();
	}

	void Application::Run()
	{
		Init();
		isRunning = true;
		m_time->Init();

		while (isRunning && m_window->IsOpen())
		{
			m_time->Update();

			m_window->BeginFrame();
			{
				Update(m_time->GetDeltaTime());
				Render();
				m_editor->Render();
			}
			m_window->EndFrame();
		}
	}

	void Application::Init()
	{
		m_editor->Init(m_window->GetWindowPtr());
		LOG_INFO("Application initialized.");
	}

	void Application::Update(float timeStep)
	{
	}

	void Application::Render()
	{
	}

	void Application::Shutdown()
	{
		LOG_INFO("Application shutdown.");
		m_editor->Shutdown();
		isRunning = false;
	}
}
