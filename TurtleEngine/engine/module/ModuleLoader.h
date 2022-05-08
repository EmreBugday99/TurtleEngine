#pragma once
#include <string>
#include <vector>

namespace TurtleCore
{
	class TurtleModule;
}

namespace TurtleEngine
{
	class ModuleLoader
	{
	public:
		virtual ~ModuleLoader() = default;
		// Gets module amount in the modules directory
		virtual unsigned int GetModuleCount() = 0;
		// Gets module names in the modules directory
		virtual std::vector<std::string> GetModuleNames() = 0;
		virtual TurtleCore::TurtleModule* LinkModule(std::string moduleName) = 0;
	};
}
