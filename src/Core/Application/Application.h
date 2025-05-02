#pragma once

#include <iostream>
#include <memory>
#include "OpenGL/Window.h"
#include "Utils/Singleton.h"
#include "Core/Time/Time.h"

namespace TRUFFLE
{
	class Application : public Singleton<Application>
	{
	private:
		bool isRunning = false;
		bool isEditorEnable = true;
		std::unique_ptr<Window> m_window;
		std::unique_ptr<Time> m_time;

	protected:
		Application();
		virtual ~Application();

	public:
		friend class Singleton<Application>;

		void Run();
		void Init();
		void Update(float timeStep);
		void Render();

		bool IsRunning() const { return isRunning; }

		float GetDeltaTime() const { return m_time->GetDeltaTime(); }
		float GetTotalTime() const { return m_time->GetTotalTime(); }
		std::size_t GetFPS() const { return m_time->GetFPS(); }
		Window *GetWindow() const { return m_window.get(); }
	};
}
