#pragma once
#include "ec/ECMemory.h"
#include "graphics/Window.h"
#include "module/ModuleManager.h"
#include "input/InputManager.h"
#include "scene/SceneManager.h"

namespace TurtleCore
{
	class Core
	{
	public:
		SceneManager SceneManager;
		ModuleManager ModuleManager;
		InputManager InputManager;
		Window* Window;

	private:
		Event BeforeCoreInitialize;
		Event AfterCoreInitialize;
		Event AfterCoreStart;
	public:
		API_EXPORT Core();
		API_EXPORT ~Core();

		API_EXPORT void Initialize();
		API_EXPORT void Start();

	private:
		void Update();
	};
}