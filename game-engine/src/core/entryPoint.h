#pragma once

#include "application.h"

#ifdef GM_PLATFORM_WINDOWS

	extern GameEngine::Application* GameEngine::createApplication();

	int main(int argc, char** argv) {
		GameEngine::Log::init();
		GM_CORE_WARN("Initialized log");
		GM_INFO("Initialized log");

		auto app = GameEngine::createApplication();

		app->run();

		delete app;
	}

#endif