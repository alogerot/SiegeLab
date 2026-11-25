#pragma once

#include "ICameraController.h"

struct placement
{
	Vector3 position;
	Vector3 target;
	cyclone::real radius;
	cyclone::real height;
	cyclone::real speed;
	cyclone::real angle;

	placement(Vector3 pos = { 0,0,0 },Vector3 targ = { 0,0,0 },cyclone::real rad = 5, cyclone::real h = 0, cyclone::real spd = 1)
	{
		position = pos;
		target = targ;
		radius = rad;
		height = h;
		speed = spd;
		angle = 0;
	}

	void clear()
	{
		position = { 0,0,0 };
		target = { 0,0,0 };
		radius = -1;
		speed = 0;
		angle = 0;
	}
};


class OrbitCamera : public ICameraController
{
private:

	placement m_data;
	

public:
	OrbitCamera();
	OrbitCamera(placement _init_data);
	void update(/*InputController*/float dt, Camera3D& camera) override;
	void reset() override;
	const Camera getCamera() override;
	void set_data(placement _data);
};

