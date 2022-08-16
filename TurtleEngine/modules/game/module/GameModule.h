#pragma once
#include "module/TurtleModule.h"

namespace TurtleCore { class Entity; }

class GameModule : TurtleCore::TurtleModule
{
public:
	GameModule();
	~GameModule() override;

	void OnModuleLoad(TurtleCore::Core* core) override;
	void OnModuleUnload(TurtleCore::Core* core) override;

	void OnModuleStart(TurtleCore::Core* core) override;
};
