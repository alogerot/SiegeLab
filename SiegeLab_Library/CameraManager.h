#pragma once
#include "CameraController.h"


class CameraManager
{
private:

	CameraController* m_camera_controller;


public:

	CameraManager(cyclone::Vector3 _target = {0,0,0},cyclone::real _radius = 3,cyclone::real _yaw = 10, cyclone::real _pitch = 10);
	void setActive();
	Camera3D getCamera();
};

