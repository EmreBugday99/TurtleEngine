#pragma once
#include "module/TurtleModule.h"
#include "API.h"

class GameModule : TurtleCore::TurtleModule
{
public:
	API_EXPORT GameModule();
	API_EXPORT ~GameModule() override;

	API_EXPORT void OnModuleLoad() override;
	API_EXPORT void OnModuleUnload() override;
};
