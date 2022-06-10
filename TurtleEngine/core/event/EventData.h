#pragma once
#include "..\API.h"

namespace TurtleCore
{
	struct EventData
	{
		const char* Name;
		void* Data;

		API_EXPORT EventData(const char* name, void* data);
	};
}