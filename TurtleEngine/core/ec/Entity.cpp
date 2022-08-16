#include "Entity.h"
#include "..\scene\Scene.h"

TurtleCore::Entity::Entity(Core* core) : Engine(core) {}

TurtleCore::Entity::~Entity()
{
}

void TurtleCore::Entity::Initialize()
{
}

void TurtleCore::Entity::Start()
{
}

void TurtleCore::Entity::Update()
{
	int waitingComponentIndex = static_cast<int>(ComponentsToStart.size());
	while (waitingComponentIndex)
	{
		waitingComponentIndex--;
		Components.push_back(ComponentsToStart[waitingComponentIndex]);
	}

	waitingComponentIndex = static_cast<int>(ComponentsToStart.size());
	while (waitingComponentIndex)
	{
		waitingComponentIndex--;
		ComponentsToStart[waitingComponentIndex]->Start();
		ComponentsToStart.erase(ComponentsToStart.begin() + waitingComponentIndex);

		if (ComponentsToStart.empty())
		{
			ComponentsToStart.clear();
			ComponentsToStart.shrink_to_fit();
		}
	}

	int componentIndex = static_cast<int>(Components.size());
	while (componentIndex)
	{
		componentIndex--;
		if (MarkedForGC)
			break;

		Components[componentIndex]->Update();
	}
}

void TurtleCore::Entity::Destroy()
{
	int componentIndex = static_cast<int>(Components.size());
	while (componentIndex)
	{
		componentIndex--;

		bool validScene = false;
		Scene& scene = Engine->SceneManager.GetActiveScene(validScene);
		if (validScene)
			scene.GetMemory().MarkObjectForGC(Components[componentIndex]);

		Components[componentIndex]->Destroy();
	}

	Components.clear();
	Components.shrink_to_fit();
}

TurtleCore::Core* TurtleCore::Entity::GetEngine() const
{
	return Engine;
}