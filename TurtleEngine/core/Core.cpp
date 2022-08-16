#include "Core.h"
#include <iostream>
#include "ec/Entity.h"
#include "event/CoreEvents.h"
#include "event/EventData.h"
#include "event/EventEnum.h"
#include "SDL_ttf.h"
#include "scene/Scene.h"

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
	SceneManager.Engine = this;

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

void TurtleCore::Core::Update()
{
	while (Window->IsRunning())
	{
		Window->Clear();

		InputManager.UpdateKeys();
		Window->HandleEvents();
		SceneManager.ActiveScene->Update(0.1f);

		Window->Render();
	}

	bool validScene = false;
	Scene& activeScene = SceneManager.GetActiveScene(validScene);
	if (validScene)
		activeScene.OnSceneUnload();

	Window->Destroy();
}