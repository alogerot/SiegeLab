#include "OrbitCamera.h"
#include <algorithm>


OrbitCamera::OrbitCamera(placement _init_data)
{
	m_data = _init_data;
}

void OrbitCamera::update(InputManager* input, float dt, Camera3D& camera)
{
	if (input)
	{
		if (input->mouse_button_down[MOUSE_BUTTON_RIGHT])
		{
			m_data.yaw += input->mouse_delta.x * 1 / 5;
			m_data.pitch += input->mouse_delta.y * 1 / 5;
			m_data.pitch = std::clamp(m_data.pitch, 20.0, 75.0);
		}
	}
	float yaw = m_data.yaw * PI / 180;
	float pitch = m_data.pitch * PI / 180;
	Vector3 newPos = { m_data.target.x + m_data.radius * cos(pitch) * cos(m_data.yaw),
					m_data.target.y + m_data.radius * sin(pitch),
					m_data.target.z + m_data.radius * sin(m_data.yaw) * cos(pitch)};
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