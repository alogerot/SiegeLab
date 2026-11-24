#include "OrbitCamera.h"


OrbitCamera::OrbitCamera(placement _init_data)
{
	m_data = _init_data;
}

void OrbitCamera::update(float dt)
{
	m_camera.target = m_data.target;
}

void OrbitCamera::set_data(placement _data)
{
	m_data = _data;
}

void OrbitCamera::reset()
{
	m_data.clear();
}