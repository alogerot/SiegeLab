#include "CameraManager.h"
#include "OrbitCamera.h"

CameraManager::CameraManager(cyclone::Vector3 _target, cyclone::real _radius , cyclone::real _yaw , cyclone::real _pitch )
{
	placement p = { _target, _radius, _yaw, _pitch };
	m_camera_controller = new OrbitCamera(p);
}