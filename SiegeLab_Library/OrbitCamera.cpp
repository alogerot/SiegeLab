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
			m_data.yaw -= input->mouse_delta.x * 1/m_data.speed ;
			m_data.pitch += input->mouse_delta.y * 1/m_data.speed ;
		}
		else if (input->keys_down[KEY_RIGHT])
			m_data.yaw += m_data.speed * dt;
		else if (input->keys_down[KEY_LEFT])
			m_data.yaw -= m_data.speed * dt;
		m_data.radius -= input->mouse_wheel_delta * dt * 30;
	}
	m_data.radius = std::clamp(m_data.radius, m_data.min_radius, m_data.max_radius);
	m_data.pitch = std::clamp(m_data.pitch, m_data.min_pitch, m_data.max_pitch);

	float yaw = m_data.yaw * PI / 180;
	float pitch = m_data.pitch * PI / 180;
	Vector3 newPos = { m_data.target.x + m_data.radius * cos(pitch) * sin(yaw),
					m_data.target.y + m_data.radius * sin(pitch),
					m_data.target.z + m_data.radius * cos(yaw) * cos(pitch)};
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

float OrbitCamera::GetRadius()
{
	return m_data.radius;
}

float OrbitCamera::GetPitch()
{
	return m_data.pitch;
}
float OrbitCamera::GetYaw()
{
	return m_data.yaw;
}