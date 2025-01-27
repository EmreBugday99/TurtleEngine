#include "ModuleFactory.h"
#include "WindowsWindowModule.h"

TurtleCore::TurtleModule* ModuleFactory::CreateModule()
{
	const auto rendererModule = reinterpret_cast<TurtleCore::TurtleModule*>(new WindowsWindowModule());
	return rendererModule;
}