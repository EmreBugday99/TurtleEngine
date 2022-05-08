#include "ModuleFactory.h"
#include "RendererModule.h"

TurtleCore::TurtleModule* ModuleFactory::CreateModule()
{
	const auto rendererModule = reinterpret_cast<TurtleCore::TurtleModule*>(new RendererModule());

	return rendererModule;
}