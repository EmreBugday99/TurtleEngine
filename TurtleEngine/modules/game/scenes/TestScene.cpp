#include "TestScene.h"
#include "ec\Entity.h"
#include "..\components\TestText.h"
#include "..\components\TestSprite.h"


void TestScene::OnSceneLoad()
{
	TurtleCore::Entity& uiTextEntity = CreateEntity();
	uiTextEntity.AddComponent<TestText>();

	TurtleCore::Entity& spriteEntity = CreateEntity();
	spriteEntity.AddComponent<TestSprite>();
}