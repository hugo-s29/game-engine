#pragma once

#include "core.h"

namespace GameEngine {

	class GAME_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// Should be defined in the client
	Application* createApplication();

}