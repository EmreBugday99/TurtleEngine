#include "TurtleObject.h"
#include <iostream>

int TurtleCore::TurtleObject::Count = 0;

TurtleCore::TurtleObject::TurtleObject() : MarkedForGC(false)
{
	Count++;
#ifdef TURTLE_DEBUG
	std::cout << "TO Count: " << Count << std::endl;
#endif // TURTLE_DEBUG
}

TurtleCore::TurtleObject::~TurtleObject()
{
	Count--;
#ifdef TURTLE_DEBUG
	std::cout << "TO Count: " << Count << std::endl;
#endif // TURTLE_DEBUG
}