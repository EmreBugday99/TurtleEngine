#include "GameModule.h"
#include "ec/Entity.h"
#include "../component/TestComponent.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include "ui/UIText.h"

GameModule::GameModule() : TurtleModule("Game") {}
GameModule::~GameModule() = default;

void GameModule::OnModuleLoad(TurtleCore::Core* core) {}

void GameModule::OnModuleUnload(TurtleCore::Core* core) {}

void GameModule::OnModuleStart(TurtleCore::Core* core)
{
	TurtleCore::Entity& entity = core->CreateEntity();

	TurtleCore::TransformComponent& transform = entity.AddComponent<TurtleCore::TransformComponent>();
	TestComponent& testComponent = entity.AddComponent<TestComponent>();
	//TurtleCore::SpriteComponent& sprite = entity.AddComponent<TurtleCore::SpriteComponent>();

	//sprite.SetTexture("assets/boss.png");

	//TurtleCore::Entity& UIEntity = core->CreateEntity();
	//TurtleCore::TransformComponent& UITransform = UIEntity.AddComponent<TurtleCore::TransformComponent>();

	//UITransform.Position.X = 0;
	//UITransform.Position.Y = 0;
	//UITransform.Size.X = 128;
	//UITransform.Size.Y = 64;

	//TurtleCore::UIText& text = UIEntity.AddComponent<TurtleCore::UIText>();
}