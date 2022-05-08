#pragma once
#include <functional>
#include "../API.h"

namespace TurtleCore
{
	struct EventData;
	class Event;

	class Listener
	{
	private:
		std::function<void(const EventData&)> Callback;

	public:
		API_EXPORT void Invoke(const EventData& evenData) const;
		API_EXPORT void BindCallback(std::function<void(const EventData&)> callback);
		API_EXPORT void UnbindCallback();
		API_EXPORT static void DeleteListener(const Listener* listenerToDelete);
	};
}