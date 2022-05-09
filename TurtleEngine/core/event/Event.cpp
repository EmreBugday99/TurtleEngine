#include "Event.h"

#include <iostream>

#include "Listener.h"

TurtleCore::Event::Event() = default;

TurtleCore::Event::~Event()
{
	for (int i = static_cast<int>(Listeners.size()) - 1; i >= 0; i--)
	{
		if (Listeners[i]->IsHeapAllocated())
		{
			Listener::DeleteListener(Listeners[i]);
			Listeners[i] = nullptr;
		}
	}

	Listeners.clear();
	Listeners.shrink_to_fit();
}

void TurtleCore::Event::AddListener(Listener * listener)
{
	std::cout << "Listener Added" << std::endl;
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
	int i = 0;
	for (const Listener* listener : Listeners)
	{
		std::cout << "Event Invoked " << i << std::endl;
		i++;
		listener->Invoke(eventData);
	}

	i = 0;
}