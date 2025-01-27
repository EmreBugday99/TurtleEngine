#pragma once
#include "event/Listener.h"
#include "module/TurtleModule.h"
#include "window/WindowsWindow.hpp"

class WindowsWindowModule : TurtleCore::TurtleModule
{
private:
	TurtleCore::Listener AfterCoreInitialize;
	WindowsWindow Window;

public:
	WindowsWindowModule();
	~WindowsWindowModule() override;

	void OnModuleLoad(TurtleCore::Core* core) override;
	void OnModuleUnload(TurtleCore::Core* core) override;
	void OnModuleStart(TurtleCore::Core* core) override;

	void InitializeWindowCallback(const TurtleCore::EventData& data);
};
