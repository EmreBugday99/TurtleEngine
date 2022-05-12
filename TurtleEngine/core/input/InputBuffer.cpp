#include "InputBuffer.h"

void TurtleCore::InputBuffer::KeyDown(int keyCode)
{
	if (KeyStates[keyCode].IsHold == false)
		KeyStates[keyCode].IsPressed = true;
	KeyStates[keyCode].IsHold = true;
	KeyStates[keyCode].IsReleased = false;

	KeysToUpdate.push_back(static_cast<KeyCode>(keyCode));
}

void TurtleCore::InputBuffer::KeyRelease(int keyCode)
{
	KeyStates[keyCode].IsPressed = false;
	KeyStates[keyCode].IsHold = false;
	KeyStates[keyCode].IsReleased = true;

	KeysToUpdate.push_back(static_cast<KeyCode>(keyCode));
}

void TurtleCore::InputBuffer::UpdateKeys()
{
	for (KeyCode keyCode : KeysToUpdate)
	{
		KeyStates[keyCode].IsPressed = false;
		KeyStates[keyCode].IsReleased = false;
	}

	KeysToUpdate.clear();
}