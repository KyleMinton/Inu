#pragma once

#include"Core.h"
#include "spdlog/spdlog.h"
#include<spdlog/fmt/ostr.h>

namespace Inu {

	class INU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define INU_CORE_TRACE(...)    ::Inu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define INU_CORE_INFO(...)     ::Inu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define INU_CORE_WARN(...)     ::Inu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define INU_CORE_ERROR(...)    ::Inu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define INU_CORE_CRITICAL(...) ::Inu::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define INU_TRACE(...)         ::Inu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define INU_INFO(...)          ::Inu::Log::GetClientLogger()->info(__VA_ARGS__)
#define INU_WARN(...)          ::Inu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define INU_ERROR(...)         ::Inu::Log::GetClientLogger()->error(__VA_ARGS__)
#define INU_CRITICAL(...)      ::Inu::Log::GetClientLogger()->critical(__VA_ARGS__)