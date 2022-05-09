#pragma once
#include "Core.h"
#include "event/Listener.h"

namespace TurtleEngine
{
	class Runtime
	{
	public:
		TurtleCore::Core Core;

	private:
		TurtleCore::Listener BeforeCoreInitialize;

	public:
		Runtime();
		~Runtime();

	private:
		void LinkModulesCallback(const TurtleCore::EventData& eventData);
	};
}
