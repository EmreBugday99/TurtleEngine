#include "RendererModule.h"
#include <iostream>
#include "Core.h"
#include "event/CoreEvents.h"
#include "event/Event.h"
#include "event/EventData.h"
#include "../graphics/SDLWindow.h"
#include "event/EventEnum.h"

RendererModule::RendererModule() : TurtleModule("SDL Renderer")
{
	AfterCoreInitialize.BindCallback
	([&](const TurtleCore::EventData& data) { InitializeWindowCallback(data); });
}

RendererModule::~RendererModule()
{
	AfterCoreInitialize.UnbindCallback();
}

void RendererModule::OnModuleLoad(TurtleCore::Core* core)
{

	TurtleCore::Event* coreEvent = TurtleCore::CoreEvents::GetEvent(GenerateEngineEventId(TurtleCore::EventEnum::AfterCoreInitialize));
	if (coreEvent == nullptr)
	{
		std::cout << "[SDL Renderer] Failed to get AfterCoreInitialize event!" << std::endl;
		return;
	}

	coreEvent->AddListener(&AfterCoreInitialize);
}

void RendererModule::OnModuleUnload(TurtleCore::Core* core)
{
	TurtleCore::Event* coreEvent = TurtleCore::CoreEvents::GetEvent(GenerateEngineEventId(TurtleCore::EventEnum::AfterCoreInitialize));
	if (coreEvent != nullptr)
		coreEvent->RemoveListener(&AfterCoreInitialize);
	AfterCoreInitialize.UnbindCallback();
	core->Window = nullptr;
}

void RendererModule::OnModuleStart(TurtleCore::Core* core) {}

void RendererModule::InitializeWindowCallback(const TurtleCore::EventData& data)
{
	// TODO: Introduce runtime safety for pointer being garbage
	if (data.Data == nullptr)
	{
		std::cout << "[SDL Renderer] CoreInitialized event invoked with NULLPTR" << std::endl;
		return;
	}

	const auto core = static_cast<TurtleCore::Core*>(data.Data);

	bool windowInitialized;
	Window.Initialize(windowInitialized, "Test Window", 600, 600);
	Window.Core = core;
	if (windowInitialized == false)
		return;

	core->Window = reinterpret_cast<TurtleCore::Window*>(&Window);
}