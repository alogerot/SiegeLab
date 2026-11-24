#include "InputManager.h"
#include <raylib.h>
void InputManager::Update()
{
	GetKeyDown();
	GetKeyRelease();

	GetMouseButtonDown();
	GetMouseButtonRelease();
	mouse_pos = GetMousePosition();
}

void InputManager::GetKeyDown()
{
	int key = GetKeyPressed();
	while (key != 0)
	{
		keys_down[key] = true;
		key = GetKeyPressed();
	}
}

void InputManager::GetMouseButtonDown()
{
	for (int i = 0; i <= 6; i++)
	{
		if (IsMouseButtonPressed(i))
			mouse_button_down[i] = true;
		
	}
}

void InputManager::GetMouseButtonRelease()
{
	for (int i = 0; i <= 6; i++)
	{
		if (IsMouseButtonUp(i))
			mouse_button_down[i] = false;
	}
}

void InputManager::GetKeyRelease()
{
	for (std::pair<int, bool> key : keys_down)
	{
		if (IsKeyReleased(key.first))
			keys_down[key.first] = false;
	}
}
