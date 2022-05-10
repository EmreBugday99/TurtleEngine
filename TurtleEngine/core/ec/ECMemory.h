#pragma once
#include <vector>
#include "../API.h"

namespace TurtleCore
{
	class TurtleObject;

	class ECMemory
	{
	private:
		std::vector<TurtleObject*> ObjectsToGarbageCollect;

	public:
		API_EXPORT void MarkObjectForGC(TurtleObject* objectToRemove);
		API_EXPORT void CollectGarbage();
	};
}
