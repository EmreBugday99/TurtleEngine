#include "Listener.h"

#include <utility>

TurtleCore::Listener::Listener(bool isHeapAllocated) : IsHeapAllocated_M(isHeapAllocated) {}

void TurtleCore::Listener::Invoke(const EventData& evenData) const
{
	Callback(evenData);
}

void TurtleCore::Listener::BindCallback(std::function<void(const EventData&)> callback)
{
	Callback = std::move(callback);
}

void TurtleCore::Listener::UnbindCallback()
{
	Callback = nullptr;
}

void TurtleCore::Listener::DeleteListener(Listener* listenerToDelete)
{
	if (listenerToDelete->IsHeapAllocated())
		delete listenerToDelete;
}

bool TurtleCore::Listener::IsHeapAllocated()
{
	return IsHeapAllocated_M;
}
