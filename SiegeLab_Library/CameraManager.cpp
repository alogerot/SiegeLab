#include "CameraManager.h"
#include "OrbitCamera.h"

void CameraManager::update(float _dt, Camera3D& _camera)
{
	m_camera_controller->update(input, _dt, _camera);
}

CameraManager::CameraManager(int _a, InputManager* _input):input(_input)
{
	if (_a == 0)
	{
		m_camera_controller = new OrbitCamera(placement({0.f, 10.f, 10.f}, {0.f, 0.f, 0.f}, 10.f,4.f,25.f, 3.f, 5.f,10.f,80.f));
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
