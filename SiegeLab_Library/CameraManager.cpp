#include "CameraManager.h"
#include "OrbitCamera.h"

void CameraManager::update(float dt, Camera3D& camera)
{
	m_camera_controller->update(input, dt, camera);
}

CameraManager::CameraManager(int a, InputManager* _input):input(_input)
{
	if (a == 0)
	{
		m_camera_controller = new OrbitCamera(placement({0.f, 10.f, 10.f}, {0.f, 0.f, 0.f}, 10.f, 3.f, 1.5f));
	}
	else
	{
		m_camera_controller = nullptr;
	}
}

const Camera CameraManager::getCamera()
{
	return m_camera_controller->getCamera();
}
