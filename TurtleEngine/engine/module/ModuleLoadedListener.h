#pragma once
#include "event/Listener.h"

namespace TurtleEngine
{
	class ModuleLoadedListener : TurtleCore::Listener
	{
	public:
		void OnNotify(void* eventData) override;
		void OnAdded(TurtleCore::Event& addedEvent) override;
		void OnRemoved(TurtleCore::Event& removedEvent) override;
	};
}
