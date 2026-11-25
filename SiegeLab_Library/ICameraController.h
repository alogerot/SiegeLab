#pragma once
#include <cyclone/core.h>
#include <raylib.h>



class ICameraController
{

protected:


public:

	virtual void update(/*InputController*/float _dt, Camera3D& _camera) = 0;
	virtual const Camera getCamera() = 0;
	virtual void reset() = 0;
};

