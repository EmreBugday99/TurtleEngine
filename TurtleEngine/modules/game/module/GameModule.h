#pragma once
#include "module/TurtleModule.h"

class GameModule : TurtleCore::TurtleModule
{
public:
	GameModule();
	~GameModule() override;

	void OnModuleLoad(TurtleCore::Core* core) override;
	void OnModuleUnload() override;

	void OnModuleStart() override;
};
