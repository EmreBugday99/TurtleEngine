#pragma once
#include "../API.h"
#include "ModuleType.h"

namespace TurtleCore
{
	class Core;

	class API_EXPORT TurtleModule
	{
	public:
		const char* ModuleName;
		ModuleTypes ModuleType;

	public:
		TurtleModule(const char* moduleName);
		virtual ~TurtleModule() = 0;
		virtual void OnModuleLoad(Core* core) = 0;
		virtual void OnModuleUnload(Core* core) = 0;
		virtual void OnModuleStart(Core* core) = 0;
	};
}
