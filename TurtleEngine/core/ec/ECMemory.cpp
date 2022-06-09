#include "ECMemory.h"
#include "Component.h"
#include "Entity.h"
#include "../TurtleObject.h"

void TurtleCore::ECMemory::StartComponents()
{
	std::vector<Component*> componentCache = ComponentWaitingToStart;

	for (int i = static_cast<int>(componentCache.size()) - 1; i >= 0 ; i--)
	{
		componentCache[i]->GetEntity().Components.push_back(componentCache[i]);
	}

	for (int i = static_cast<int>(componentCache.size()) - 1; i >= 0; i--)
	{
		componentCache[i]->Start();
	}

	for (Component* component : componentCache)
	{
		for (int i = static_cast<int>(ComponentWaitingToStart.size()) - 1; i >= 0 ; i--)
		{
			if (component == ComponentWaitingToStart[i])
				ComponentWaitingToStart.erase(ComponentWaitingToStart.begin() + i);
		}
	}

	componentCache.clear();
}

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
