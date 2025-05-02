#include "Core/Application/Application.h"

#include "Core/GUI/GLFWTestWindow.h"

namespace TRUFFLE
{
	Application::Application()
	{
		m_window = std::make_unique<Window>(1200, 800, "Truffle Engine");
		m_time = std::make_unique<Time>([this]()
																		{ return m_window->GetTime(); });
	}

	Application::~Application() {}

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
			}
			m_window->EndFrame();
		}
	}

	void Application::Init()
	{
	}

	void Application::Update(float timeStep)
	{
	}

	void Application::Render()
	{
		ApplicationInfo();
	}
}
