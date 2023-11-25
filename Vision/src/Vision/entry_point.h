#pragma once


#ifdef VISION_PLATFORM_WINDOWS

extern Vision::Application* Vision::createApplication();

int main(int argc, char** argv)
{
	auto app = Vision::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif // VISION_PLATFORM_WINDOWS
