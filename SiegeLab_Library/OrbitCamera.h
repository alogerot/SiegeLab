#pragma once

#include "CameraController.h"

struct placement
{
	Vector3 target;
	cyclone::real radius;
	cyclone::real yaw;
	cyclone::real pitch;

	void clear()
	{
		target = { 0,0,0 };
		radius = -1;
		yaw = 0;
		pitch = 0;
	}
};


class OrbitCamera : public CameraController
{
private:

	placement m_data;
	

public:
	OrbitCamera();
	OrbitCamera(placement _init_data);
	void update(/*InputController*/float dt) override;
	void reset() override;
	void set_data(placement _data);
};

