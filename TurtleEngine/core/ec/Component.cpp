#include "Component.h"

TurtleCore::Component::Component(Entity* owner) :Owner(owner) {}

void TurtleCore::Component::Initialize()
{
}

void TurtleCore::Component::Start()
{
}

void TurtleCore::Component::Update()
{
}

void TurtleCore::Component::Destroy()
{
}

void TurtleCore::Component::GetEntity(const Entity* entity) const
{
	entity = Owner;
}
