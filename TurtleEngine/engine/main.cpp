#include "Runtime.h"

int main()
{
	TurtleEngine::Runtime runtime;

	runtime.Core.Initialize();
	runtime.Core.Start();

	return 0;
}