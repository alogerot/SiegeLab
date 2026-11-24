#pragma once
#include <cyclone/core.h>
#include <raylib.h>



class CameraController
{

protected:

	Camera3D m_camera;

public:

	virtual void update(/*InputController*/float dt) = 0;
	Camera3D getCamera() { return m_camera; };
	virtual void reset() = 0;
};

