#include "TestComponent.h"
#include "components/TransformComponent.h"
#include "ec/Entity.h"
#include "ui/UIText.h"

TurtleCore::Entity* UIEntity;

TestComponent::TestComponent() = default;
TestComponent::~TestComponent() = default;

void TestComponent::Initialize()
{
}

void TestComponent::Start()
{
	UIEntity = &Owner->GetEngine()->CreateEntity();
	TurtleCore::TransformComponent& UITransform = UIEntity->AddComponent<TurtleCore::TransformComponent>();

	UITransform.Position.X = 0;
	UITransform.Position.Y = 0;
	UITransform.Size.X = 128;
	UITransform.Size.Y = 64;

	TurtleCore::UIText& text = UIEntity->AddComponent<TurtleCore::UIText>();
	text.SetFont("assets/Roboto-Regular.ttf", 12);
	text.SetColor({ 255, 0, 0, 255 });
	text.SetText("hello World");
	text.UpdateText();
}

void TestComponent::Update()
{
	if (Owner->GetEngine()->InputManager.IsKeyDown(TurtleCore::KEYCODE_A))
	{
		UIEntity->GetComponent<TurtleCore::TransformComponent>()->Position -= {1, 1};
	}
	if (Owner->GetEngine()->InputManager.IsKeyDown(TurtleCore::KEYCODE_D))
	{
		UIEntity->GetComponent<TurtleCore::TransformComponent>()->Position += {1,1};
	}

	if (Owner->GetEngine()->InputManager.IsKeyDown(TurtleCore::KEYCODE_F))
	{
		UIEntity->GetComponent<TurtleCore::UIText>()->SetText("I am different");
		UIEntity->GetComponent<TurtleCore::UIText>()->UpdateText();
	}
	if (Owner->GetEngine()->InputManager.IsKeyDown(TurtleCore::KEYCODE_E))
	{
		UIEntity->GetComponent<TurtleCore::UIText>()->SetColor({255, 255, 255, 255});
		UIEntity->GetComponent<TurtleCore::UIText>()->UpdateText();
	}
	if (Owner->GetEngine()->InputManager.IsKeyDown(TurtleCore::KEYCODE_X))
	{
		UIEntity->GetComponent<TurtleCore::UIText>()->SetFont("assets/WaterBrush-Regular.ttf", 24);
		UIEntity->GetComponent<TurtleCore::UIText>()->UpdateText();
	}
}

void TestComponent::Destroy()
{
}