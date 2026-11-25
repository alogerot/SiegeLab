#pragma once

#include "ICameraController.h"
#include "InputManager.h"

struct placement
{
	Vector3 position;
	Vector3 target;
	cyclone::real radius , min_radius, max_radius;
	cyclone::real height;
	cyclone::real speed;
	cyclone::real yaw;
	cyclone::real pitch, min_pitch, max_pitch;

	placement(Vector3 pos = { 0,0,0 },Vector3 targ = { 0,0,0 },
		cyclone::real rad = 5,cyclone::real _min_rad = 4, cyclone::real _max_rad = 25,
		cyclone::real h = 0,cyclone::real spd = 1, 
		cyclone::real _min_pitch = 10, cyclone::real _max_pitch = 80)
	{
		position = pos;
		target = targ;
		radius = rad;
		min_radius = _min_rad;
		max_radius = _max_rad;
		height = h;
		speed = spd;
		yaw = 0;
		pitch = 0;
		min_pitch = _min_pitch;
		max_pitch = _max_pitch;
	}

	void clear()
	{
		position = { 0,0,0 };
		target = { 0,0,0 };
		radius = -1;
		speed = 0;
		yaw = 0;
		pitch = 0;
	}
};


class OrbitCamera : public ICameraController
{
private:

	placement m_data;
	

public:
	OrbitCamera();
	OrbitCamera(placement _init_data);
	void update(InputManager* input, float dt, Camera3D& camera) override;
	void reset() override;
	const Camera getCamera() override;
	void set_data(placement _data);
};

