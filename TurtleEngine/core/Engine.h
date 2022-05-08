#pragma once
#include "API.h"

class Engine
{
public:
    API_EXPORT Engine();
    API_EXPORT ~Engine();
    API_EXPORT int AddThreeNumbers(int x, int y, int z);
    API_EXPORT void SayHello();
};
