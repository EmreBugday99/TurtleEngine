#pragma once
#include <unordered_map>
#include <string>
#include "../API.h"


namespace TurtleCore
{
	class Event;

	class CoreEvents
	{
	private:
		API_EXPORT static std::unordered_map<std::string, Event*> EventMap;

	public:
		API_EXPORT static void AddEvent(const std::string& key, Event* event);
		API_EXPORT static void RemoveEvent(const std::string& key);
		API_EXPORT static bool HasEvent(const std::string& key);
		API_EXPORT static Event* GetEvent(const std::string& key);
	};
}
