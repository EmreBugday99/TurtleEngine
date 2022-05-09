#include "GameModule.h"

GameModule::GameModule() : TurtleModule("Game") {}
GameModule::~GameModule() = default;

void GameModule::OnModuleLoad(TurtleCore::Core* core) {}

void GameModule::OnModuleUnload(TurtleCore::Core* core) {}

void GameModule::OnModuleStart(TurtleCore::Core* core) {}