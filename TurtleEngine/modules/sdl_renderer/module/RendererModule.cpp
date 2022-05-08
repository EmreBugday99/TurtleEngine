#include "RendererModule.h"
#include <iostream>

#include "Core.h"
#include "event/CoreEvents.h"
#include "event/Event.h"
#include "event/EventData.h"
#include "../graphics/SDLWindow.h"

RendererModule::RendererModule() : TurtleModule("SDL Renderer"), Core(nullptr)
{
	CoreInitializeListener.BindCallback
	([&](const TurtleCore::EventData& data) { OnCoreInitialize(data); });
}

RendererModule::~RendererModule() = default;

void RendererModule::OnModuleLoad(TurtleCore::Core* core)
{
	TurtleCore::Event* coreEvent = TurtleCore::CoreEvents::GetEvent("CoreInitialize");
	if (coreEvent == nullptr)
	{
		std::cout << "[SDL Renderer] Failed to get CoreInitialize event!" << std::endl;
		return;
	}

	coreEvent->AddListener(&CoreInitializeListener);
}

void RendererModule::OnModuleUnload() {}

void RendererModule::OnModuleStart() {}

void RendererModule::OnCoreInitialize(const TurtleCore::EventData& data)
{
	if (data.Data == nullptr)
	{
		std::cout << "[SDL Renderer] CoreInitialized event invoked with NULLPTR" << std::endl;
		return;
	}

	Core = static_cast<TurtleCore::Core*>(data.Data);
	const auto window = new SDLWindow;

	bool windowInitialized;
	window->Initialize(windowInitialized, "Test Window", 600, 600);
	if (windowInitialized == false)
	{
		delete window;
		return;
	}

	Core->Window = reinterpret_cast<TurtleCore::Window*>(window);

}