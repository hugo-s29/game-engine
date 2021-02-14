#pragma once

#ifdef GM_PLATFORM_WINDOWS

	#ifdef GM_BUILD_DLL
		#define GAME_ENGINE_API __declspec(dllexport)
	#else
		#define GAME_ENGINE_API __declspec(dllimport)
	#endif

#else
	
#error Only windows supported

#endif