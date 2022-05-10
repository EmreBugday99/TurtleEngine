#pragma once
#include "ec/ECMemory.h"
#include "graphics/Window.h"
#include "module/ModuleManager.h"

namespace TurtleCore
{
	class Entity;

	class Core
	{
	public:
		ModuleManager ModuleManager;
		Window* Window;

	private:
		Event BeforeCoreInitialize;
		Event AfterCoreInitialize;
		Event AfterCoreStart;

		ECMemory Memory;
		std::vector<Entity*> EntitiesInGame;

	public:
		API_EXPORT Core();
		API_EXPORT ~Core();

		API_EXPORT void Initialize();
		API_EXPORT void Start();

		API_EXPORT ECMemory& GetMemory();
		API_EXPORT Entity& CreateEntity();
		API_EXPORT void RemoveEntity(Entity* entityToRemove);

	private:
		void Update();
	};

}