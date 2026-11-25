#include "CameraManager.h"
#include "OrbitCamera.h"

void CameraManager::update(float _dt, Camera3D& _camera)
{
	m_camera_controller->update(_dt, _camera);
}

CameraManager::CameraManager(int _a)
{
	if (_a == 0)
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
