#include <iostream>

#include "event/CoreEvents.h"
#include "event/Event.h"
#include "module/ModuleLoadedListener.h"
#include "module/ModuleManager.h"

#include "module/TurtleModule.h"
#include "module/WindowsModuleLoader.h"

typedef TurtleCore::TurtleModule* (__cdecl* ModuleFactory)();

int main()
{
	auto manager = new TurtleCore::ModuleManager;
	auto moduleLoader = new TurtleEngine::WindowsModuleLoader;

	TurtleCore::Event testEvent;
	const auto listener = reinterpret_cast<TurtleCore::Listener*>(new TurtleEngine::ModuleLoadedListener);

	TurtleCore::CoreEvents::AddEvent("ModuleLoad", &testEvent);
	TurtleCore::CoreEvents::GetEvent("ModuleLoad")->AddListener(listener);

	for (const auto& moduleName : moduleLoader->GetModuleNames())
	{
		TurtleCore::TurtleModule* linkedModule = moduleLoader->LinkModule("modules/" + moduleName);
		if (linkedModule != nullptr)
		{
			std::cout << "Linked: " << linkedModule->ModuleName << std::endl;
			bool successful = false;
			manager->AddModule(*linkedModule, successful);

			if (successful == false)
				std::cout << "Failed to add module" << linkedModule->ModuleName << std::endl;
		}
	}

	manager->LoadAllModules();

	return 0;
}