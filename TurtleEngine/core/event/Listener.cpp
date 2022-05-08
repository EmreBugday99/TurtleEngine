#include "Listener.h"

#include <utility>

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

void TurtleCore::Listener::DeleteListener(const Listener* listenerToDelete)
{
	delete listenerToDelete;
}
