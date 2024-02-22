#pragma once
#include "Base/Types.h"
#include "Base/Platform.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>
#include <spdlog/fmt/bundled/color.h>

#include <string>

PRAGMA_CLANG_DIAGNOSTIC_PUSH;
PRAGMA_CLANG_DIAGNOSTIC_IGNORE(-Wformat-security);
PRAGMA_CLANG_DIAGNOSTIC_IGNORE(-Wnon-pod-varargs);

class DebugHandler
{
public:
	template <typename... Args>
	inline static void Print(spdlog::level::level_enum level, const std::string& message, Args... args)
	{
		spdlog::log(level, message, std::forward<Args>(args)...);
	}

	template <typename... Args>
	inline static void Print(const std::string& message, Args... args)
	{
		Print(spdlog::level::level_enum::info, message, std::forward<Args>(args)...);
	}

	template <typename... Args>
	inline static void PrintTrace(const std::string& message, Args... args)
	{
		Print(spdlog::level::level_enum::trace, message, std::forward<Args>(args)...);
	}

	template <typename... Args>
	inline static void PrintDebug(const std::string& message, Args... args)
	{
		Print(spdlog::level::level_enum::debug, message, std::forward<Args>(args)...);
	}

	template <typename... Args>
	inline static void PrintWarning(const std::string& message, Args... args)
	{
		Print(spdlog::level::level_enum::warn, message, std::forward<Args>(args)...);
	}

	template <typename... Args>
	inline static void PrintError(const std::string& message, Args... args)
	{
		Print(spdlog::level::level_enum::err, message, std::forward<Args>(args)...);
	}

	template <typename... Args>
	inline static void PrintFatal(const std::string& message, Args... args)
	{
		Print(spdlog::level::level_enum::critical, message, std::forward<Args>(args)...);

		ReleaseModeBreakpoint();
	}

	template <typename... Args>
	inline static void Assert(bool assertion, const std::string& message, Args... args)
	{
		if (!assertion)
		{
			PrintFatal(message, std::forward<Args>(args)...);
		}
	}

private:
};
PRAGMA_CLANG_DIAGNOSTIC_POP;