#pragma once

namespace TurtleCore
{
	struct EventData
	{
		EventData(const char* name, void* data);

		const char* Name;
		void* Data;
	};
}