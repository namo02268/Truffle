#pragma once

#include <iostream>
#include <memory>
#include "OpenGL/OpenGLWindow.h"
#include "Utils/Singleton.h"
#include "Core/Time/Time.h"
#include "Editor/Editor.h"
#include "Renderer/Renderer.h"

namespace TRUFFLE
{
	class Application : public Singleton<Application>
	{
	private:
		bool isRunning = false;
		bool isEditorEnable = false;

		std::unique_ptr<OpenGLWindow> m_window;
		std::unique_ptr<Time> m_time;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<Editor> m_editor;

	protected:
		Application();
		virtual ~Application();

	public:
		friend class Singleton<Application>;

		void Run();
		void Init();
		void Update(float timeStep);
		void Render();
		void Shutdown();

		bool IsRunning() const { return isRunning; }
		bool IsEditorEnable() const { return isEditorEnable; }

		float GetDeltaTime() const { return m_time->GetDeltaTime(); }
		float GetTotalTime() const { return m_time->GetTotalTime(); }
		std::size_t GetFPS() const { return m_time->GetFPS(); }
		Window *GetWindow() const { return m_window.get(); }
	};
}
