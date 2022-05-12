#pragma once
#include "InputBuffer.h"
#include "KeyCodes.h"
#include "../API.h"

namespace TurtleCore
{
	class InputManager
	{
	public:
		InputBuffer Buffer;

		void UpdateKeys();
		API_EXPORT bool IsKeyPressed(KeyCode keyCode) const;
		API_EXPORT bool IsKeyDown(KeyCode keyCode) const;
		API_EXPORT bool IsKeyReleased(KeyCode keyCode) const;
	};
}
