#include "CoreEvents.h"

std::unordered_map<std::string, TurtleCore::Event*> TurtleCore::CoreEvents::EventMap;

void TurtleCore::CoreEvents::AddEvent(const std::string& key, Event* event)
{
	EventMap[key] = event;
}

void TurtleCore::CoreEvents::RemoveEvent(const std::string& key)
{
	if (HasEvent(key))
		EventMap.erase(key);
}

bool TurtleCore::CoreEvents::HasEvent(const std::string& key)
{
	if (EventMap.find(key) == EventMap.end())
		return false;

	return true;
}

TurtleCore::Event* TurtleCore::CoreEvents::GetEvent(const std::string& key)
{
	if (HasEvent(key))
		return EventMap.at(key);

	return nullptr;
}