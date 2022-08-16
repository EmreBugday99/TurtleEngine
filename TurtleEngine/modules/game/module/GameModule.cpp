#include "GameModule.h"
#include "ec/Entity.h"
#include "Core.h"
#include "scene/SceneManager.h"
#include "../scenes/TestScene.h"

GameModule::GameModule() : TurtleModule("Game")
{
	ModuleType = TurtleCore::ModuleTypes::GameModule;
}

GameModule::~GameModule() = default;

void GameModule::OnModuleLoad(TurtleCore::Core* core)
{
	std::cout << "Turtle Module: [" << ModuleName << "] Loaded" << std::endl;
}

void GameModule::OnModuleUnload(TurtleCore::Core* core)
{
	bool validScene;
	TurtleCore::Scene& activeScene = core->SceneManager.GetActiveScene(validScene);
	if (validScene)
		activeScene.GetMemory().CollectGarbage();

	std::cout << "Turtle Module: [" << ModuleName << "] Unloaded" << std::endl;
}

void GameModule::OnModuleStart(TurtleCore::Core* core)
{
	auto& testScene = core->SceneManager.LoadScene<TestScene>();
	std::cout << "Turtle Module: [" << ModuleName << "] Started" << std::endl;
}