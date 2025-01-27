#include "WindowsWindowModule.h"
#include <iostream>
#include "Core.h"
#include "event/CoreEvents.h"
#include "event/Event.h"
#include "event/EventData.h"
#include "event/EventEnum.h"

WindowsWindowModule::WindowsWindowModule() : TurtleModule("Windows Window")
{
	AfterCoreInitialize.BindCallback
	([&](const TurtleCore::EventData& data) { InitializeWindowCallback(data); });

	ModuleType = TurtleCore::ModuleTypes::CoreModule;
}

WindowsWindowModule::~WindowsWindowModule()
{
	AfterCoreInitialize.UnbindCallback();
}

void WindowsWindowModule::OnModuleLoad(TurtleCore::Core* core)
{

	TurtleCore::Event* coreEvent = TurtleCore::CoreEvents::GetEvent(GenerateEngineEventId(TurtleCore::EventEnum::AfterCoreInitialize));
	if (coreEvent == nullptr)
		return;

	coreEvent->AddListener(&AfterCoreInitialize);

	bool success = false;
	Window.Initialize(success, "Test Window 222", 400, 600);
	
}

void WindowsWindowModule::OnModuleUnload(TurtleCore::Core* core)
{
	TurtleCore::Event* coreEvent = TurtleCore::CoreEvents::GetEvent(GenerateEngineEventId(TurtleCore::EventEnum::AfterCoreInitialize));
	if (coreEvent != nullptr)
		coreEvent->RemoveListener(&AfterCoreInitialize);

	AfterCoreInitialize.UnbindCallback();
	core->Window = nullptr;
}

void WindowsWindowModule::OnModuleStart(TurtleCore::Core* core)
{
}

void WindowsWindowModule::InitializeWindowCallback(const TurtleCore::EventData& data)
{
	if (data.Data == nullptr)
		return;

	const auto core = static_cast<TurtleCore::Core*>(data.Data);

	bool success = false;
	Window.CreateWindowsWindow(success);
	if (success)
		core->Window = reinterpret_cast<TurtleCore::Window*>(&Window);
}