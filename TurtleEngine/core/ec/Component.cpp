#include "Component.h"

TurtleCore::Component::Component() : Owner(nullptr) {}

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

TurtleCore::Entity& TurtleCore::Component::GetEntity() const
{
	return *Owner;
}