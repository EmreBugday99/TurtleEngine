#include "EnemyComponent.h"
#include "event\CoreEvents.h"
#include "event\Event.h"
#include "components\TransformComponent.h"
#include "ec\Component.h"
#include "ec\Entity.h"

EnemyComponent::~EnemyComponent() = default;

void EnemyComponent::Initialize()
{
	PlayerActionlistener.BindCallback([&](const TurtleCore::EventData& data) { OnPlayerAction(data); });
	movementAxis = 1;
}

void EnemyComponent::Start()
{
	TurtleCore::Event* playerMoveEvent = TurtleCore::CoreEvents::GetEvent("PlayerAction");
	playerMoveEvent->AddListener(&PlayerActionlistener);
}

void EnemyComponent::Update()
{
}

void EnemyComponent::Destroy()
{
}

void EnemyComponent::OnPlayerAction(const TurtleCore::EventData& data)
{
	auto transform = Owner->GetComponent<TurtleCore::TransformComponent>();
	
	transform->Position += 10 * movementAxis;
	movementAxis *= -1;
}