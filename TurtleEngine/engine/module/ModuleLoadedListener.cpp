#include "ModuleLoadedListener.h"

#include <iostream>

#include "module/TurtleModule.h"

void TurtleEngine::ModuleLoadedListener::OnNotify(void* eventData)
{
	TurtleCore::TurtleModule* loadedModule = static_cast<TurtleCore::TurtleModule*>(eventData);

	std::cout << "Module Loaded Notification" << std::endl;
	std::cout << loadedModule->ModuleName << std::endl;
	
}

void TurtleEngine::ModuleLoadedListener::OnAdded(TurtleCore::Event& addedEvent)
{
}

void TurtleEngine::ModuleLoadedListener::OnRemoved(TurtleCore::Event& removedEvent)
{
}