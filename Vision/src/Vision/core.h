#pragma once


#ifdef VISION_PLATFORM_WINDOWS
	#ifdef VISION_BUILD_DLL
		#define VISION_API _declspec(dllexport)
	#else
		#define VISION_API _declspec(dllimport)
	#endif
#else
	#error Vision only supports Windows!
#endif