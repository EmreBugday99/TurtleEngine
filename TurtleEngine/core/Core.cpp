#include "Core.h"

#include "event/CoreEvents.h"
#include "event/EventData.h"

TurtleCore::Core::Core() : Window(nullptr)
{
	CoreEvents::AddEvent("CoreInitialize", &CoreInitializeEvent);
	CoreEvents::AddEvent("CoreStart", &CoreStartEvent);
}

TurtleCore::Core::~Core()
{
	CoreEvents::RemoveEvent("CoreInitialize");
	CoreEvents::RemoveEvent("CoreStart");

	delete Window;
}

void TurtleCore::Core::Initialize()
{
	CoreInitializeEvent.Invoke(EventData("CoreInitialize", this));
}

void TurtleCore::Core::Start()
{
	CoreStartEvent.Invoke(EventData("CoreStart", this));
}
