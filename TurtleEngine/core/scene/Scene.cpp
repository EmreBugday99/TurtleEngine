#include "Scene.h"
#include "..\ec\Entity.h"
#include "..\Core.h"

TurtleCore::Entity& TurtleCore::Scene::CreateEntity()
{
	Entity* newEntity = new Entity(Engine);
	newEntity->Initialize();
	EntitiesWaitingToStart.push_back(newEntity);

	return *newEntity;
}

void TurtleCore::Scene::OnSceneUnload()
{
	int entityIndex = static_cast<int>(Entities.size());
	while (entityIndex)
	{
		entityIndex--;

		Entities[entityIndex]->Destroy();
		Memory.MarkObjectForGC(Entities[entityIndex]);
	}

	Entities.clear();
	Entities.shrink_to_fit();
	Memory.CollectGarbage();
}

void TurtleCore::Scene::Update(const float& deltaTime)
{
	StartWaitingEntities();

	int entityIndex = static_cast<int>(Entities.size());
	while (entityIndex)
	{
		entityIndex--;
		Entities[entityIndex]->Update();
	}
}

void TurtleCore::Scene::StartWaitingEntities()
{
	int entityIndex = static_cast<int>(EntitiesWaitingToStart.size());
	while (entityIndex)
	{
		entityIndex--;

		EntitiesWaitingToStart[entityIndex]->Start();
		Entities.push_back(EntitiesWaitingToStart[entityIndex]);

		/*
		* Entity creating shouldn't happen frequently since it's an expensive operation
		* Therefore the vector shouldn't utilize unused memory.
		*/
		if (entityIndex == 0)
		{
			EntitiesWaitingToStart.clear();
			EntitiesWaitingToStart.shrink_to_fit();
		}
	}
}

void TurtleCore::Scene::SetCore(Core* core)
{
	Engine = core;
}

void TurtleCore::Scene::DestroyEntity(Entity* entityToDestroy)
{
	int entityIndex = static_cast<int>(Entities.size());
	while (entityIndex)
	{
		entityIndex--;
		
		if (Entities[entityIndex] == entityToDestroy)
		{
			Entities.erase(Entities.begin() + entityIndex);
			entityToDestroy->Destroy();
			Memory.MarkObjectForGC(entityToDestroy);
		}
	}
}

TurtleCore::ECMemory& TurtleCore::Scene::GetMemory()
{
	return Memory;
}