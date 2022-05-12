#pragma once
#include <vector>
#include "../API.h"

namespace TurtleCore
{
	class Component;
	class TurtleObject;

	class ECMemory
	{
	private:
		friend class Entity;

		std::vector<TurtleObject*> ObjectsToGarbageCollect;
		std::vector<Component*> ComponentWaitingToStart;

	public:
		API_EXPORT void StartComponents();
		API_EXPORT void MarkObjectForGC(TurtleObject* objectToRemove);
		API_EXPORT void CollectGarbage();
	};
}
