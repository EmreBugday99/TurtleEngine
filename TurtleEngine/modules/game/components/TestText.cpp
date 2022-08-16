#include "TestText.h"
#include "ec\Entity.h"
#include "ui\UIText.h"
#include "components\TransformComponent.h"
#include "components\SpriteComponent.h"

void TestText::Initialize()
{
}

void TestText::Start()
{
	auto& textComponent = Owner->AddComponent<TurtleCore::UIText>();
	textComponent.SetFont("assets/Roboto-Regular.ttf", 24);
	textComponent.SetColor({ 255, 0, 0, 255 });
	textComponent.SetText("This is a test text.");
	textComponent.UpdateText();

	// Remove self after adding UI Component.
	Owner->RemoveComponent<TestText>();
}

void TestText::Update()
{
}

void TestText::Destroy()
{
	std::cout << "TestText Destroyed!" << std::endl;
}