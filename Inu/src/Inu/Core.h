#pragma once

#ifdef INU_PLATFORM_WINDOWS
	#ifdef INU_BUILD_DLL
		#define INU_API __declspec(dllexport)
	#else
		#define INU_API __declspec(dllimport)
	#endif
#else
	#error Inu Engine only supports Windows! (for now...)

#endif

#ifdef INU_ENABLE_ASSERTS
	#define INU_ASSERT(x, ...) { if(!(x)) { INU_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define INU_CORE_ASSERT(x, ...) { if(!(x)) { INU_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define INU_ASSERT(x, ...)
	#define INU_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)