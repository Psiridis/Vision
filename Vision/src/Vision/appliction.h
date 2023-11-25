#pragma once
#include "core.h"

namespace Vision {
	class  VISION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
};

