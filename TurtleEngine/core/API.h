#pragma once

#ifdef TURTLE_OS_WINDOWS
#define API_EXPORT __declspec(dllexport)
#define API_IMPORT __declspec(dllimport)
#endif // TURTLE_OS_WINDOWS
