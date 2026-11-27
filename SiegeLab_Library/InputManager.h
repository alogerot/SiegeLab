#pragma once
#include <map>
#include <raylib.h>
class InputManager
{
public:


	void Update();

	Vector2 mouse_pos;
	Vector2 mouse_delta;
	std::map<int, bool> keys_down;
	bool mouse_button_down[7];
	float mouse_wheel_delta = 0;

private:
	void GetKeyDown();
	void GetMouseButtonDown();
	void GetMouseButtonRelease();
	void GetKeyRelease();
};

