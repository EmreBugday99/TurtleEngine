#pragma once
#include "../API.h"

namespace TurtleCore
{
	class Core;

	class API_EXPORT TurtleModule
	{
	public:
		const char* ModuleName;

	public:
		TurtleModule(const char* moduleName);
		virtual ~TurtleModule() = 0;
		virtual void OnModuleLoad(Core* core) = 0;
		virtual void OnModuleUnload() = 0;
		virtual void OnModuleStart() = 0;
	};
}
