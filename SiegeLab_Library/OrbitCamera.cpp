#include "OrbitCamera.h"


OrbitCamera::OrbitCamera(placement _init_data)
{
	m_data = _init_data;
}

void OrbitCamera::update(float dt, Camera3D& camera)
{
	m_data.angle += m_data.speed * dt;
	Vector3 newPos = 
	{ 
		m_data.target.x + m_data.radius * cos(m_data.angle), 
		m_data.height, 
		m_data.target.z + m_data.radius * sin(m_data.angle) 
	};
	m_data.position = newPos;
	camera = getCamera();
}

void OrbitCamera::set_data(placement _data)
{
	m_data = _data;
}

void OrbitCamera::reset()
{
	m_data.clear();
}

const Camera OrbitCamera::getCamera()
{
	Camera camera = { 0 };
	camera.position = m_data.position;
	camera.target = m_data.target;
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	return camera;
}