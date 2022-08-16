#include "TestSprite.h"
#include "ec\Entity.h"
#include "components\TransformComponent.h"
#include "components\SpriteComponent.h"

void TestSprite::Initialize()
{
}

void TestSprite::Start()
{
	auto& transformComponent = Owner->AddComponent<TurtleCore::TransformComponent>();
	transformComponent.Size.Set({ 100, 200 });
	transformComponent.Position.Set(20);

	auto& spriteComponent = Owner->AddComponent<TurtleCore::SpriteComponent>();
	spriteComponent.SetTexture("assets/test_sprite.png");

	// Remove self after adding UI Component.
	Owner->RemoveComponent<TestSprite>();
}

void TestSprite::Update()
{
}

void TestSprite::Destroy()
{
	std::cout << "TestSprite Destroyed!" << std::endl;
}