#include "Runtime.h"

int main()
{
	TurtleEngine::Runtime runtime;

	runtime.Core.Initialize();
	runtime.Core.Start();

	while (true)
	{
	}

	return 0;
}