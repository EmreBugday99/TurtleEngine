#pragma once

#ifdef TURTLE_OS_WINDOWS

#include "ModuleLoader.h"

namespace TurtleEngine
{
	class WindowsModuleLoader : ModuleLoader
	{
	public:
		unsigned int GetModuleCount() override;
		std::vector<std::string> GetModuleNames() override;
		TurtleCore::TurtleModule* LinkModule(std::string moduleName) override;
	};
}

#endif // TURTLE_OS_WINDOWS