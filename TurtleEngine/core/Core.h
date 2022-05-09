#pragma once
#include "graphics/Window.h"
#include "module/ModuleManager.h"

namespace TurtleCore
{
	class Core
	{
	public:
		ModuleManager ModuleManager;
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
	};

}