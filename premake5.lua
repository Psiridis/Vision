workspace "TheZoomies"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
 
  project "TheZoomies"
    location "TheZoomies"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.hpp",
      "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
      "%{prj.name}/src"
    }
  
	filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
		
	filter "configurations:Debug"
			defines "THEZOOMIES_DEBUG"
			symbols "On" 

		filter "configurations:Release"
			defines "THEZOOMIES_RELEASE"
			optimize "On" 

		filter "configurations:Dist"
			defines "THEZOOMIES_DIST"
			optimize "On"
    
