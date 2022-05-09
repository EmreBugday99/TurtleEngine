#pragma once
#include <string>

namespace TurtleCore
{
	enum EventEnum : unsigned int
	{
		BeforeCoreInitialize = 0,
		AfterCoreInitialize,
		AfterCoreStart,
		AfterModuleLoad,
		AfterModuleUnload,
		AfterModuleStart
	};

	inline static std::string GenerateEngineEventId(const unsigned int& eventId)
	{
		return "turtle_event_" + std::to_string(eventId);
	}
}
