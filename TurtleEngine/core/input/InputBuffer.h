#pragma once
#include "KeyCodes.h"
#include "KeyState.h"
#include <vector>
#include "../API.h"

namespace TurtleCore
{
	class InputBuffer
	{
	public:
		KeyState KeyStates[SDL_NUM_SCANCODES] = {{false, false, false}};
		std::vector<KeyCode> KeysToUpdate;

		API_EXPORT void KeyDown(int keyCode);
		API_EXPORT void KeyRelease(int keyCode);
		API_EXPORT void UpdateKeys();
	};
}
