#pragma once
#include "Scene.h"

namespace TurtleCore
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		/// <summary>
		/// Returns the currently active scene
		/// </summary>
		/// <param name="validScene">If the returned scene reference is valid and can be used safely</param>
		/// <returns>Active Scene</returns>
		API_EXPORT Scene& GetActiveScene(bool& validScene);

		template<class T>
		API_EXPORT T& LoadScene()
		{
			if (ActiveScene != nullptr)
			{
				ActiveScene->OnSceneUnload();
				delete ActiveScene;
				ActiveScene = nullptr;
			}

			T* newScene = new T();
			newScene->SetCore(Engine);
			newScene->OnSceneLoad();

			ActiveScene = newScene;

			return *newScene;
		}

	private:
		friend class Core;
		Scene* ActiveScene;
		Core* Engine;
	};
}