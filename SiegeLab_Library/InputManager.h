#pragma once
#include <map>
class InputManager
{
public:


	void Update();

	Vector2 mouse_pos;
	std::map<int, bool> keys_down;
	bool mouse_button_down[7];

private:
	void GetKeyDown();
	void GetMouseButtonDown();
	void GetMouseButtonRelease();
	void GetKeyRelease();
};

