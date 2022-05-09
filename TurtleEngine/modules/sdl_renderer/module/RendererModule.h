#pragma once
#include "event/Listener.h"
#include "module/TurtleModule.h"
#include "../graphics/SDLWindow.h"

class RendererModule : TurtleCore::TurtleModule
{
private:
	TurtleCore::Listener AfterCoreInitialize;
	SDLWindow Window;

public:
	RendererModule();
	~RendererModule() override;

	void OnModuleLoad(TurtleCore::Core* core) override;
	void OnModuleUnload(TurtleCore::Core* core) override;
	void OnModuleStart(TurtleCore::Core* core) override;

	void InitializeWindowCallback(const TurtleCore::EventData& data);
};
