#pragma once

#include "precompile.h"

#include "core.h"
#include "spdlog/spdlog.h"

namespace Vision 
{
	class VISION_API Logger
	{
	public:
		Logger();
		~Logger();

		std::shared_ptr<spdlog::logger>& getCoreLogger();
		std::shared_ptr<spdlog::logger>& getClientLogger();

	private:
		std::shared_ptr<spdlog::logger> s_core_logger;
		std::shared_ptr<spdlog::logger> s_client_logger;
	};
	
};

//Core log macros
#define VISION_CORE_TRACE(...) ::Vision::Log::getCoreLogger()->trace(_VA_ARGS_)
#define VISION_CORE_INFO(...)  ::Vision::Log::getCoreLogger()->info(_VA_ARGS_)
#define VISION_CORE_WARN(...)  ::Vision::Log::getCoreLogger()->warn(_VA_ARGS_)
#define VISION_CORE_ERROR(...) ::Vision::Log::getCoreLogger()->error(_VA_ARGS_)
#define VISION_CORE_FATAL(...) ::Vision::Log::getCoreLogger()->fatal(_VA_ARGS_)

//Client log macros
#define VISION_CLIENT_TRACE(...) ::Vision::Log::getClientLogger()->trace(_VA_ARGS_)
#define VISION_CLIENT_INFO(...)  ::Vision::Log::getClientLogger()->info(_VA_ARGS_)
#define VISION_CLIENT_WARN(...)  ::Vision::Log::getClientLogger()->warn(_VA_ARGS_)
#define VISION_CLIENT_ERROR(...) ::Vision::Log::getClientLogger()->error(_VA_ARGS_)
#define VISION_CLIENT_FATAL(...) ::Vision::Log::getClientLogger()->fatal(_VA_ARGS_)
