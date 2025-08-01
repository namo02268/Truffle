#include "Core/Application/Application.h"
#include "Core/Logger/Logger.h"
#include "Scene/HelloTriangle.h"

namespace TRUFFLE
{
	Application::Application()
	{
		WindowProps props("Truffle Engine", 1200, 800);
		m_window = std::make_unique<OpenGLWindow>(props);
		m_time = std::make_unique<Time>([this]()
																		{ return m_window->GetTime(); });
		m_renderer = std::make_unique<Renderer>(props.Width, props.Height);
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

		while (isRunning && m_window->IsOpen())
		{
			{
				m_time->Update();
				Update(m_time->GetDeltaTime());
			}
			{
				m_renderer->BeginFrame();
				Render();
				if (isEditorEnable)
					m_editor->Render();
				m_renderer->EndFrame();
			}
			m_window->OnUpdate();
		}
	}

	void Application::Init()
	{
		LOG_INFO("Initializing application...");
		m_time->Init();
		m_renderer->Init();
		m_editor->Init(static_cast<GLFWwindow *>(m_window->GetNativeWindow()));

		SetScene(std::make_unique<HelloTriangle>());
	}

	void Application::Update(float timeStep)
	{
		if (m_activeScene)
			m_activeScene->OnUpdate(timeStep);
	}

	void Application::Render()
	{
		if (m_activeScene)
			m_activeScene->OnRender();
	}

	void Application::Shutdown()
	{
		LOG_INFO("Application shutdown.");
		m_editor->Shutdown();
		isRunning = false;
	}

	void Application::SetScene(std::unique_ptr<Scene> scene)
	{
		if (m_activeScene)
			m_activeScene->OnShutdown();

		m_activeScene = std::move(scene);
		if (m_activeScene)
			m_activeScene->OnInit();

		LOG_INFO("Scene changed.");
	}
}
