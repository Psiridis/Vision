workspace "Vision"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to the root
IncludeDirs = {}
IncludeDirs["GLFW"] = "Vision/vendor/GLFW/include/"

include "Vision/vendor/GLFW" -- this is the directory of corresponding premake file

project "Vision"
	location "Vision"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "precompile.h"
	pchsource "Vision/src/precompile.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include/",
		"%IncludeDirs.GLFW"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"VISION_PLATFORM_WINDOWS",
			"VISION_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VISION_DEBUG"
		symbols "On" 

	filter "configurations:Release"
		defines "VISION_RELEASE"
		optimize "On" 

	filter "configurations:Dist"
		defines "VISION_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Vision/vendor/spdlog/include",
		"Vision/src"
	}

	links
	{
		"Vision" 
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"VISION_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "VISION_DEBUG"
		symbols "On" 

	filter "configurations:Release"
		defines "VISION_RELEASE"
		optimize "On" 

	filter "configurations:Dist"
		defines "VISION_DIST"
		optimize "On"