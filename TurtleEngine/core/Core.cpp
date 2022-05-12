#include "Core.h"
#include <iostream>
#include "ec/Entity.h"
#include "event/CoreEvents.h"
#include "event/EventData.h"
#include "event/EventEnum.h"
#include "SDL_ttf.h"

TurtleCore::Core::Core() : Window(nullptr)
{
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::BeforeCoreInitialize), &BeforeCoreInitialize);
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::AfterCoreInitialize), &AfterCoreInitialize);
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::AfterCoreStart), &AfterCoreStart);
}

TurtleCore::Core::~Core()
{
	ModuleManager.UnloadAllModules();

	CoreEvents::RemoveEvent(GenerateEngineEventId(EventEnum::BeforeCoreInitialize));
	CoreEvents::RemoveEvent(GenerateEngineEventId(EventEnum::AfterCoreInitialize));
	CoreEvents::RemoveEvent(GenerateEngineEventId(EventEnum::AfterCoreStart));
}

void TurtleCore::Core::Initialize()
{
	BeforeCoreInitialize.Invoke(EventData("BeforeCoreInitialize", this));
	ModuleManager.Initialize(this);

	if (TTF_Init() == -1)
	{
		std::cout << "TTF Failed To Initialize!" << std::endl;
		return;
	}

	ModuleManager.LoadAllModules();
	AfterCoreInitialize.Invoke(EventData("AfterCoreInitialize", this));
}

void TurtleCore::Core::Start()
{
	ModuleManager.StartAllModules();
	AfterCoreStart.Invoke(EventData("AfterCoreStart", this));

	Update();
}

TurtleCore::ECMemory& TurtleCore::Core::GetMemory()
{
	return Memory;
}

TurtleCore::Entity& TurtleCore::Core::CreateEntity()
{
	Entity* entity = new Entity(this);
	entity->Initialize();
	EntitiesInGame.push_back(entity);
	entity->Start();

	return *entity;
}

void TurtleCore::Core::RemoveEntity(Entity* entityToRemove)
{
	for (int i = 0; i < static_cast<int>(EntitiesInGame.size()); i++)
	{
		if (EntitiesInGame[i] == entityToRemove)
		{
			EntitiesInGame.erase(EntitiesInGame.begin() + i);
			break;
		}
	}
}

void TurtleCore::Core::Update()
{
	while (Window->IsRunning())
	{
		Window->Clear();

		Memory.StartComponents();
		InputManager.UpdateKeys();
		Window->HandleEvents();

		for (int i = static_cast<int>(EntitiesInGame.size()) - 1; i >= 0; i--)
		{
			EntitiesInGame[i]->Update();
		}

		Window->Render();
	}

	for (Entity* entity : EntitiesInGame)
	{
		entity->Destroy();
	}

	Memory.CollectGarbage();
	Window->Destroy();
}