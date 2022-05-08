#include "GameModule.h"
#include <iostream>

GameModule::GameModule() : TurtleModule("GameModule") {}

void GameModule::OnModuleLoad()
{
	std::cout << "Loaded " << ModuleName << std::endl;
}

void GameModule::OnModuleUnload()
{
	std::cout << "Unloaded " << ModuleName << std::endl;
}

GameModule::~GameModule()
{
	std::cout << "Deleted " << ModuleName << std::endl;
}