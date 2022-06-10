#include "ModuleFactory.h"
#include "LevelModule.h"

TurtleCore::TurtleModule* ModuleFactory::CreateModule()
{
	LevelModule* levelModule = new LevelModule();

	return reinterpret_cast<TurtleCore::TurtleModule*>(levelModule);
}