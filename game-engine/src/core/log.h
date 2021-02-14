#pragma once

#include <spdlog/spdlog.h>

#include "core.h"

namespace GameEngine {

	class GAME_ENGINE_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; };
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};

}

#define GM_CORE_ERROR(...) ::GameEngine::Log::getCoreLogger()->error(__VA_ARGS__)
#define GM_CORE_WARN(...)  ::GameEngine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GM_CORE_INFO(...)  ::GameEngine::Log::getCoreLogger()->info(__VA_ARGS__)
#define GM_CORE_TRACE(...) ::GameEngine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GM_CORE_FATAL(...) ::GameEngine::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define GM_ERROR(...) ::GameEngine::Log::getClientLogger()->error(__VA_ARGS__)
#define GM_WARN(...)  ::GameEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define GM_INFO(...)  ::GameEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define GM_TRACE(...) ::GameEngine::Log::getClientLogger()->trace(__VA_ARGS__)
#define GM_FATAL(...) ::GameEngine::Log::getClientLogger()->fatal(__VA_ARGS__)