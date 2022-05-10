#include "Entity.h"

TurtleCore::Entity::Entity(Core* core) : Engine(core) {}

TurtleCore::Entity::~Entity() = default;

void TurtleCore::Entity::Initialize()
{
}

void TurtleCore::Entity::Start()
{
}

void TurtleCore::Entity::Update()
{
}

void TurtleCore::Entity::Destroy()
{
	for (Component* component : Components)
	{
		Engine->GetMemory().MarkObjectForGC(component);
	}
	Components.clear();
	Components.shrink_to_fit();

	Engine->RemoveEntity(this);
	Engine->GetMemory().MarkObjectForGC(this);
}