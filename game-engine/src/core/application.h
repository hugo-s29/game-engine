#pragma once

#include "core.h"
#include "window.h"

namespace GameEngine {

	class GAME_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	// Should be defined in the client
	Application* createApplication();

}