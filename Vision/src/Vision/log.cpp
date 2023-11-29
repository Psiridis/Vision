#include "precompile.h"
#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Vision
{
	Logger::Logger()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_core_logger = spdlog::stdout_color_mt("VISION");
		s_core_logger->set_level(spdlog::level::trace);

		s_client_logger = spdlog::stdout_color_mt("APP");
		s_client_logger->set_level(spdlog::level::trace);
	}


	Logger::~Logger()
	{

	}


	std::shared_ptr<spdlog::logger>& Logger::getCoreLogger()
	{
		return s_core_logger;
	}


	std::shared_ptr<spdlog::logger>& Logger::getClientLogger()
	{
		return s_client_logger;
	}
}