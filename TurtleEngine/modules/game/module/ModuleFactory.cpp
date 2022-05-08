#include "ModuleFactory.h"
#include "GameModule.h"

TurtleCore::TurtleModule* ModuleFactory::CreateModule()
{
	GameModule* gameModule = new GameModule();

	return reinterpret_cast<TurtleCore::TurtleModule*>(gameModule);
}