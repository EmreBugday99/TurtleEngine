#include "Entity.h"

TurtleCore::Entity::Entity(Core* core) : Engine(core) {}

TurtleCore::Entity::~Entity()
{
	std::cout << "Entity deleted" << std::endl;
};

void TurtleCore::Entity::Initialize()
{
}

void TurtleCore::Entity::Start()
{
}

void TurtleCore::Entity::Update()
{
	int componentIndex = static_cast<int>(Components.size());
	while (componentIndex)
	{
		if (MarkedForGC)
			break;

		componentIndex--;
		Components[componentIndex]->Update();
	}
}

void TurtleCore::Entity::Destroy()
{
	for (Component* component : Components)
	{
		Engine->GetMemory().MarkObjectForGC(component);
		component->Destroy();
	}
	Components.clear();
	Components.shrink_to_fit();

	Engine->RemoveEntity(this);
	Engine->GetMemory().MarkObjectForGC(this);
}

TurtleCore::Core* TurtleCore::Entity::GetEngine() const
{
	return Engine;
}
