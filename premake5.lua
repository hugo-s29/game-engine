workspace "game-engine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir.GLFW = "game-engine/vendor/glfw/include"
IncludeDir.spdlog = "game-engine/vendor/spdlog/include"

include "game-engine/vendor/glfw"

project "game-engine"

	location "game-engine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "gmpch.h"
	pchsource "game-engine/src/gmpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		IncludeDir.spdlog,
		IncludeDir.GLFW,
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"GM_PLATFORM_WINDOWS",
			"GM_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:Debug"
		defines "GM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GM_DIST"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"game-engine/vendor/spdlog/include",
		"game-engine/src"
	}

	links {
		"game-engine"
	}

	filter "system:windows"
cppdialect "C++17"
staticruntime "On"
systemversion "latest"

defines {
    "GM_PLATFORM_WINDOWS"
}

filter "configurations:Debug"
defines "GM_DEBUG"
symbols "On"

filter "configurations:Release"
defines "GM_RELEASE"
optimize "On"

filter "configurations:Dist"
defines "GM_DIST"
optimize "On"
