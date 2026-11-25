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

	placement(Vector3 _pos = { 0,0,0 },Vector3 _targ = { 0,0,0 },cyclone::real _rad = 5, cyclone::real _h = 0, cyclone::real _spd = 1)
	{
		position = _pos;
		target = _targ;
		radius = _rad;
		height = _h;
		speed = _spd;
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
	void update(/*InputController*/float _dt, Camera3D& _camera) override;
	void reset() override;
	const Camera getCamera() override;
	void set_data(placement _data);
};

