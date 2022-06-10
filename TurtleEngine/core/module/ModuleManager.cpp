#include "ModuleManager.h"
#include "TurtleModule.h"
#include "../event/CoreEvents.h"
#include "../event/Event.h"
#include "../event/EventData.h"
#include "../event/EventEnum.h"

TurtleCore::ModuleManager::ModuleManager (): Engine(nullptr)
{
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::AfterModuleLoad), &ModuleLoadEvent);
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::AfterModuleUnload), &ModuleUnloadEvent);
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::AfterModuleStart), &ModuleStartEvent);
}

TurtleCore::ModuleManager::~ModuleManager()
{
	for (int i = static_cast<int>(Modules.size()) - 1; i >= 0; i--)
	{
		Modules[i]->OnModuleUnload(Engine);
		delete Modules[i];
	}

	CoreEvents::RemoveEvent(GenerateEngineEventId(EventEnum::AfterModuleLoad));
	CoreEvents::RemoveEvent(GenerateEngineEventId(EventEnum::AfterModuleUnload));
	CoreEvents::RemoveEvent(GenerateEngineEventId(EventEnum::AfterModuleStart));
}

void TurtleCore::ModuleManager::Initialize(Core* core)
{
	Engine = core;
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

			turtleModule->OnModuleUnload(Engine);
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

void TurtleCore::ModuleManager::LoadAllModules()
{
	for (TurtleModule* turtleModule : Modules)
	{
		bool isCustomModule;
		IsCustomModule(turtleModule, isCustomModule);
		if (isCustomModule)
			continue;

		turtleModule->OnModuleLoad(Engine);

		ModuleLoadEvent.Invoke(EventData("ModuleLoad", turtleModule));
	}
}

void TurtleCore::ModuleManager::StartAllModules()
{
	for (TurtleModule* turtleModule : Modules)
	{
		bool isCustomModule;
		IsCustomModule(turtleModule, isCustomModule);
		if (isCustomModule)
			continue;

		turtleModule->OnModuleStart(Engine);
		ModuleStartEvent.Invoke(EventData("ModuleStart", turtleModule));
	}
}

void TurtleCore::ModuleManager::UnloadAllModules()
{
	for (TurtleModule* turtleModule : Modules)
	{
		bool isCustomModule;
		IsCustomModule(turtleModule, isCustomModule);
		if (isCustomModule)
			continue;

		bool success = false;
		RemoveModule(turtleModule->ModuleName, success);
		//TODO: Handle failed module unloading
	}
}

void TurtleCore::ModuleManager::IsCustomModule(TurtleModule* turtleModule, bool& result)
{
	result = false;
	if (turtleModule->ModuleType == ModuleTypes::CustomModule)
		result = true;
}
