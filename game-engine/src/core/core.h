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

#ifdef GM_ENABLE_ASSERTS
	#define GM_ASSERT(x, ...) { if(!(x)} {HZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GM_CORE_ASSERT(x, ...) { if(!(x)} {HZ_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GM_ASSERT(x, ...)
	#define GM_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)