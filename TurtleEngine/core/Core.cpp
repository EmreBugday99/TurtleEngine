#include "Core.h"

#include "event/CoreEvents.h"
#include "event/EventData.h"
#include "event/EventEnum.h"

TurtleCore::Core::Core() : Window(nullptr)
{
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::BeforeCoreInitialize), &BeforeCoreInitialize);
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::AfterCoreInitialize), &AfterCoreInitialize);
	CoreEvents::AddEvent(GenerateEngineEventId(EventEnum::AfterCoreStart), & AfterCoreStart);
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

	ModuleManager.LoadAllModules();
	AfterCoreInitialize.Invoke(EventData("AfterCoreInitialize", this));
}

void TurtleCore::Core::Start()
{
	ModuleManager.StartAllModules();
	AfterCoreStart.Invoke(EventData("AfterCoreStart", this));
}
