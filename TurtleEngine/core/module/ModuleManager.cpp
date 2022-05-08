#include "ModuleManager.h"
#include "TurtleModule.h"
#include "../event/CoreEvents.h"
#include "../event/Event.h"
#include "../event/EventData.h"

TurtleCore::ModuleManager::ModuleManager()
{
	CoreEvents::AddEvent("ModuleLoad", &ModuleLoadEvent);
	CoreEvents::AddEvent("ModuleUnload", &ModuleUnloadEvent);
	CoreEvents::AddEvent("ModuleStart", &ModuleStartEvent);
}

TurtleCore::ModuleManager::~ModuleManager()
{
	for (int i = static_cast<int>(Modules.size()) - 1; i >= 0; i--)
	{
		Modules[i]->OnModuleUnload();
		delete Modules[i];
	}

	CoreEvents::RemoveEvent("ModuleLoad");
	CoreEvents::RemoveEvent("ModuleUnload");
	CoreEvents::RemoveEvent("ModuleStart");
}

void TurtleCore::ModuleManager::AddModule(TurtleModule& moduleToAdd, bool& result)
{
	bool hasModule = false;
	HasModule(moduleToAdd.ModuleName, hasModule);

	if (hasModule)
	{
		result = false;
		return;
	}

	Modules.push_back(&moduleToAdd);
	result = true;
}

void TurtleCore::ModuleManager::RemoveModule(const char* moduleToRemove, bool& result)
{
	for (int i = static_cast<int>(Modules.size()) - 1; i >= 0; i--)
	{
		if (strcmp(moduleToRemove, Modules[i]->ModuleName) == 0)
		{
			TurtleModule* turtleModule = Modules[i];

			Modules.erase(Modules.begin() + i);

			turtleModule->OnModuleUnload();
			ModuleUnloadEvent.Invoke(EventData("ModuleUnload", turtleModule));
			delete turtleModule;

			result = true;
			return;
		}
	}
}

void TurtleCore::ModuleManager::HasModule(const char* moduleName, bool& result) const
{
	result = false;

	for (const TurtleModule* turtleModule : Modules)
	{
		if (strcmp(moduleName, turtleModule->ModuleName) == 0)
		{
			result = true;
			return;
		}
	}
}

TurtleCore::TurtleModule* TurtleCore::ModuleManager::GetModule(const char* moduleName, bool& result) const
{
	result = false;

	for (TurtleModule* turtleModule : Modules)
	{
		if (strcmp(moduleName, turtleModule->ModuleName) == 0)
		{
			result = true;
			return turtleModule;
		}
	}

	return nullptr;
}

void TurtleCore::ModuleManager::LoadAllModules(Core* core) const
{
	for (TurtleModule* turtleModule : Modules)
	{
		turtleModule->OnModuleLoad(core);

		ModuleLoadEvent.Invoke(EventData("ModuleLoad", turtleModule));
	}
}

void TurtleCore::ModuleManager::StartAllModules() const
{
	for (TurtleModule* turtleModule : Modules)
	{
		turtleModule->OnModuleStart();
		ModuleStartEvent.Invoke(EventData("ModuleStart", turtleModule));
	}
}
