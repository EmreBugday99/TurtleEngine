#pragma once
#include "../API.h"

namespace TurtleCore
{
	class API_EXPORT TurtleModule
	{
	public:
		const char* ModuleName;

	public:
		TurtleModule(const char* moduleName);
		virtual ~TurtleModule() = 0;
		virtual void OnModuleLoad() = 0;
		virtual void OnModuleUnload() = 0;
	};
}
