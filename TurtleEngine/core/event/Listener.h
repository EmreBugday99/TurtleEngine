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
		bool IsHeapAllocated_M;
		std::function<void(const EventData&)> Callback;

	public:
		API_EXPORT Listener(bool isHeapAllocated = false);
		API_EXPORT void Invoke(const EventData& evenData) const;
		API_EXPORT void BindCallback(std::function<void(const EventData&)> callback);
		API_EXPORT void UnbindCallback();
		API_EXPORT static void DeleteListener(Listener* listenerToDelete);
		API_EXPORT bool IsHeapAllocated();
	};
}