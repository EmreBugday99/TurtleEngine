#include "InputManager.h"

void TurtleCore::InputManager::UpdateKeys()
{
	Buffer.UpdateKeys();
}

bool TurtleCore::InputManager::IsKeyPressed(KeyCode keyCode) const
{
	return Buffer.KeyStates[keyCode].IsPressed;
}

bool TurtleCore::InputManager::IsKeyDown(KeyCode keyCode) const
{
	return Buffer.KeyStates[keyCode].IsHold;
}

bool TurtleCore::InputManager::IsKeyReleased(KeyCode keyCode) const
{
	return Buffer.KeyStates[keyCode].IsReleased;
}