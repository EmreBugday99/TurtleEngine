#include <iostream>
#include "event/CoreEvents.h"
#include "event/Event.h"
#include "module/ModuleManager.h"
#include "module/TurtleModule.h"
#include "module/WindowsModuleLoader.h"
#include "Core.h"

typedef TurtleCore::TurtleModule* (__cdecl* ModuleFactory)();

int main()
{
	TurtleCore::Core core;
	TurtleCore::ModuleManager manager;
	TurtleEngine::WindowsModuleLoader moduleLoader;

	TurtleCore::Event testEvent;

	std::cout << "Modules In Directory: " << moduleLoader.GetModuleCount() << std::endl;

	for (const auto& moduleName : moduleLoader.GetModuleNames())
	{
		TurtleCore::TurtleModule* linkedModule = moduleLoader.LinkModule("modules/" + moduleName);
		if (linkedModule == nullptr)
		{
			std::cout << "Failed to link with " << moduleName << std::endl;
			continue;
		}

		std::cout << "Linked: " << linkedModule->ModuleName << std::endl;
		bool successful = false;
		manager.AddModule(*linkedModule, successful);

		if (successful == false)
			std::cout << "Failed to add module" << linkedModule->ModuleName << std::endl;
	}

	manager.LoadAllModules(&core);

	core.Initialize();

	manager.StartAllModules();

	while (true) {}

	return 0;
}