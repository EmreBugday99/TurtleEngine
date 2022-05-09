#include "Runtime.h"
#include <iostream>
#include "event/CoreEvents.h"
#include "event/EventEnum.h"
#include "module/WindowsModuleLoader.h"
#include "module/TurtleModule.h"

TurtleEngine::Runtime::Runtime()
{
	BeforeCoreInitialize.BindCallback
	([&](const TurtleCore::EventData& data) { LinkModulesCallback(data); });

	const auto beforeInitializeEvent = TurtleCore::CoreEvents::GetEvent(GenerateEngineEventId(TurtleCore::EventEnum::BeforeCoreInitialize));
	if (beforeInitializeEvent != nullptr)
		beforeInitializeEvent->AddListener(&BeforeCoreInitialize);
}

TurtleEngine::Runtime::~Runtime()
{
	TurtleCore::Event* beforeInitializeEvent = TurtleCore::CoreEvents::GetEvent(GenerateEngineEventId(TurtleCore::EventEnum::BeforeCoreInitialize));
	if (beforeInitializeEvent != nullptr)
		beforeInitializeEvent->RemoveListener(&BeforeCoreInitialize);
	BeforeCoreInitialize.UnbindCallback();
}

void TurtleEngine::Runtime::LinkModulesCallback(const TurtleCore::EventData& eventData)
{
#ifdef TURTLE_OS_WINDOWS

	WindowsModuleLoader moduleLoader;
	std::cout << "Number Of Modules: " << moduleLoader.GetModuleCount() << std::endl;
	for (auto libraryName : moduleLoader.GetModuleNames())
	{
		TurtleCore::TurtleModule* turtleModule = moduleLoader.LinkModule("modules/" + libraryName);
		if (turtleModule == nullptr)
			continue;

		bool moduleAddedSuccess = false;
		Core.ModuleManager.AddModule(*turtleModule, moduleAddedSuccess);
	}

#endif // TURTLE_OS_WINDOWS
}