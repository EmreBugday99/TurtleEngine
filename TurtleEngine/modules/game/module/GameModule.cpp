#include "GameModule.h"
#include "ec/Entity.h"
#include "components/TransformComponent.h"
#include "ui/UIText.h"
#include "Core.h"

GameModule::GameModule() : TurtleModule("Game") {}
GameModule::~GameModule() = default;

void GameModule::OnModuleLoad(TurtleCore::Core* core) {}

void GameModule::OnModuleUnload(TurtleCore::Core* core) {}

void GameModule::OnModuleStart(TurtleCore::Core* core)
{
	TurtleCore::Entity& welcomeEntity = core->CreateEntity();
	auto& welcomeText = welcomeEntity.AddComponent<TurtleCore::UIText>();

	welcomeText.SetFont("assets/Roboto-Regular.ttf", 24);
	welcomeText.SetColor({ 255, 0, 0, 255 });
	welcomeText.SetText("Please say 'Start Game' to start the game...");
	welcomeText.UpdateText();
}