#include "SceneManager.h"

TurtleCore::SceneManager::SceneManager() : ActiveScene(nullptr), Engine(nullptr) {}

TurtleCore::SceneManager::~SceneManager()
{
	if (ActiveScene != nullptr)
	{
		ActiveScene->OnSceneUnload();
		ActiveScene = nullptr;
	}

	Engine = nullptr;
}

TurtleCore::Scene& TurtleCore::SceneManager::GetActiveScene(bool& validScene)
{
	validScene = ActiveScene != nullptr;
	return *ActiveScene;
}