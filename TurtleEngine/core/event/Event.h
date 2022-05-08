#pragma once
#include <vector>
#include "../API.h"

namespace TurtleCore
{
	struct EventData;
	class Listener;

	class Event
	{
	private:
		std::vector<Listener*> Listeners;

	public:
		API_EXPORT Event();
		API_EXPORT ~Event();

		API_EXPORT void Invoke(const EventData& eventData) const;
		API_EXPORT void AddListener(Listener* listener);
		API_EXPORT void RemoveListener(Listener* listener);
		API_EXPORT unsigned int ListenerAmount() const;
	};
}
