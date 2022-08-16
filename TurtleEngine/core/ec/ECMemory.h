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

	public:
		API_EXPORT void MarkObjectForGC(TurtleObject* objectToRemove);
		API_EXPORT void CollectGarbage();
	};
}
