#include "Engine.h"

#include <iostream>

Engine::Engine()
{
}

Engine::~Engine()
{
}

int Engine::AddThreeNumbers(int x, int y, int z)
{
    return x + y + z;
}

void Engine::SayHello()
{
    std::cout << "Hello from Engine!" << std::endl;
}
