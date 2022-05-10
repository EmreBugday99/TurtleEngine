#pragma once
#include <iostream>

namespace TurtleCore
{
	class DummyClass
	{
	public:
		template<typename T>
		void PrintTypeName()
		{
			std::cout << typeid(T).name() << std::endl;
		}
	};
}
