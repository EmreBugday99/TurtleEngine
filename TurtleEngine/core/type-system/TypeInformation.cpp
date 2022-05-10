#include "TypeInformation.h"
#include <typeinfo>
#include "../TurtleObject.h"

TurtleCore::TypeInformation::TypeInformation()
	: TypeId(nullptr), Size(0), Pointer(nullptr), Initialized(false) {}

void TurtleCore::TypeInformation::Initialize(TurtleObject* object)
{
	TypeId = typeid(object).name();
	Pointer = object;
	Initialized = true;
}

const char* TurtleCore::TypeInformation::GetTypeId() const
{
	return TypeId;
}

unsigned short TurtleCore::TypeInformation::GetSize() const
{
	return Size;
}

void* TurtleCore::TypeInformation::GetPointer() const
{
	return Pointer;
}

bool TurtleCore::TypeInformation::IsInitialized() const
{
	return Initialized;
}
