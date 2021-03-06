#include "Event.h"
#include "Listener.h"

TurtleCore::Event::Event() = default;

TurtleCore::Event::~Event()
{
	Listeners.clear();
	Listeners.shrink_to_fit();
}

void TurtleCore::Event::AddListener(Listener * listener)
{
	Listeners.push_back(listener);
}

void TurtleCore::Event::RemoveListener(Listener * listener)
{
	for (int i = static_cast<int>(Listeners.size()) - 1; i >= 0; i--)
	{
		if (Listeners[i] == listener)
			Listeners.erase(Listeners.begin() + i);
	}
}

unsigned int TurtleCore::Event::ListenerAmount() const
{
	return static_cast<unsigned int>(Listeners.size());
}

void TurtleCore::Event::Invoke(const EventData & eventData) const
{
	for (const Listener* listener : Listeners)
	{
		listener->Invoke(eventData);
	}
}