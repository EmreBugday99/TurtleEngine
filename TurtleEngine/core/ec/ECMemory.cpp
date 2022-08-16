#include "ECMemory.h"
#include "../TurtleObject.h"

void TurtleCore::ECMemory::MarkObjectForGC(TurtleObject* objectToRemove)
{
	ObjectsToGarbageCollect.push_back(objectToRemove);
	objectToRemove->MarkedForGC = true;
}

void TurtleCore::ECMemory::CollectGarbage()
{
	for (int i = static_cast<int>(ObjectsToGarbageCollect.size()) - 1; i >= 0; i--)
	{
		delete ObjectsToGarbageCollect[i];
		ObjectsToGarbageCollect[i] = nullptr;
	}

	ObjectsToGarbageCollect.clear();
}
