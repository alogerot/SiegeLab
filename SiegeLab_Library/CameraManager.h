#pragma once
#include "ICameraController.h"
#include "InputManager.h"


class CameraManager
{
private:

	ICameraController* m_camera_controller;


public:

	void update(float dt, Camera3D& camera);
	CameraManager(int = 0, InputManager* _input = nullptr);
	void setActive();
	const Camera getCamera();

	InputManager* input = nullptr;
};

