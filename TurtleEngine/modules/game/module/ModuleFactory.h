#pragma once
#include "API.h"

namespace TurtleCore
{
	class TurtleModule;
}

class API_EXPORT ModuleFactory
{
public:
	static TurtleCore::TurtleModule* CreateModule();
};
