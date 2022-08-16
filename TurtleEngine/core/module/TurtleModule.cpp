#include "TurtleModule.h"

TurtleCore::TurtleModule::TurtleModule(const char* moduleName)
	: ModuleName(moduleName), ModuleType(ModuleTypes::CustomModule) {}

TurtleCore::TurtleModule::~TurtleModule()
{
}