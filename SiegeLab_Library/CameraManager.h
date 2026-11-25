#pragma once
#include "ICameraController.h"


class CameraManager
{
private:

	ICameraController* m_camera_controller;


public:

	void update(float dt, Camera3D& camera);
	CameraManager(int = 0);
	void setActive();
	const Camera getCamera();
};

