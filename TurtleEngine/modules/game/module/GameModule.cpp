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
	auto& welcomeTransorm = welcomeEntity.AddComponent<TurtleCore::TransformComponent>();
	auto& welcomeText = welcomeEntity.AddComponent<TurtleCore::UIText>();

	welcomeTransorm.Position.X = core->Window->Width / 2;
	welcomeTransorm.Size.X = 128;
	welcomeTransorm.Size.Y = 64;

	welcomeText.SetFont("assets/Roboto-Regular.ttf", 12);
	welcomeText.SetColor({ 255, 0, 0, 255 });
	welcomeText.SetText("Hello World");
	welcomeText.UpdateText();
}