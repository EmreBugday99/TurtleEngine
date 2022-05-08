#pragma once
#include "../API.h"

namespace TurtleCore
{
	class Event;

	class API_EXPORT Listener
	{
	public:
		virtual ~Listener();
		virtual void OnNotify(void* eventData) = 0;
		virtual void OnAdded(Event& addedEvent) = 0;
		virtual void OnRemoved(Event& removedEvent) = 0;
		static void DeleteListener(const Listener* listenerToDelete);
	};
}