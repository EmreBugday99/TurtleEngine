#pragma once
#include "..\API.h"
#include <vector>
#include "..\ec\ECMemory.h"

namespace TurtleCore
{
	class Entity;
	class Core;
	class Scene
	{
	private:
		ECMemory Memory;

		std::vector<Entity*> Entities;
		std::vector<Entity*> EntitiesWaitingToStart;
		Core* Engine;

	private:
		friend class SceneManager;
		void StartWaitingEntities();

	public:
		API_EXPORT virtual void OnSceneLoad() = 0;
		API_EXPORT virtual void OnSceneUnload();
		API_EXPORT virtual void Update(const float& deltaTime);

		API_EXPORT void SetCore(Core* core);
		API_EXPORT Entity& CreateEntity();
		API_EXPORT void DestroyEntity(Entity* entityToDestroy);
		API_EXPORT ECMemory& GetMemory();
	};
}