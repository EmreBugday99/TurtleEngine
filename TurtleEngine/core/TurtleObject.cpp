#include "TurtleObject.h"
#include <iostream>

int TurtleCore::TurtleObject::Count = 0;

TurtleCore::TurtleObject::TurtleObject()
{
	Count++;
	std::cout << "TO Count: " << Count << std::endl;
}

TurtleCore::TurtleObject::~TurtleObject()
{
	Count--;
	std::cout << "TO Count: " << Count << std::endl;
}
