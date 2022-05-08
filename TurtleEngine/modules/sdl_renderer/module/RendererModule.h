#pragma once
#include "event/Listener.h"
#include "module/TurtleModule.h"

class RendererModule : TurtleCore::TurtleModule
{
private:
	TurtleCore::Listener CoreInitializeListener;
	TurtleCore::Core* Core;

public:
	RendererModule();
	~RendererModule() override;

	void OnModuleLoad(TurtleCore::Core* core) override;
	void OnModuleUnload() override;
	void OnModuleStart() override;

	void OnCoreInitialize(const TurtleCore::EventData& data);
};