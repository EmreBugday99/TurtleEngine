#include "GameModule.h"
#include "ec/Entity.h"
#include "../component/TestComponent.h"

GameModule::GameModule() : TurtleModule("Game") {}
GameModule::~GameModule() = default;

void GameModule::OnModuleLoad(TurtleCore::Core* core) {}

void GameModule::OnModuleUnload(TurtleCore::Core* core) {}

void GameModule::OnModuleStart(TurtleCore::Core* core)
{
	TurtleCore::Entity& entity = core->CreateEntity();
	entity.AddComponent<TestComponent>();
}