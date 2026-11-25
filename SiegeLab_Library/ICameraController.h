#pragma once
#include <cyclone/core.h>
#include <raylib.h>



class ICameraController
{

protected:


public:

	virtual void update(/*InputController*/float dt, Camera3D& camera) = 0;
	virtual const Camera getCamera() = 0;
	virtual void reset() = 0;
};

