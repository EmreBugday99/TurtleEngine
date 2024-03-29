#pragma once
#include <vector>
#include "../API.h"
#include "../event/Event.h"

namespace TurtleCore
{
	class Core;
	class TurtleModule;

	class ModuleManager
	{
	private:
		std::vector<TurtleModule*> Modules;
		Event ModuleLoadEvent;
		Event ModuleUnloadEvent;
		Event ModuleStartEvent;
		Core* Engine;

	public:
		API_EXPORT ModuleManager();
		API_EXPORT ~ModuleManager();

		API_EXPORT void Initialize(Core* core);
		API_EXPORT void AddModule(TurtleModule& moduleToAdd, bool& result);
		API_EXPORT void RemoveModule(const char* moduleToRemove, bool& result);
		API_EXPORT void HasModule(const char* moduleName, bool& result) const;
		API_EXPORT TurtleModule* GetModule(const char* moduleName, bool& result) const;
		API_EXPORT void LoadAllModules();
		API_EXPORT void StartAllModules();
		API_EXPORT void UnloadAllModules();

	private:
		void IsCustomModule(TurtleModule* turtleModule, bool& result);
	};
}
