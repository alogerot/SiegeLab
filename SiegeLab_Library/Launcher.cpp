#include "Launcher.h"
#include <raymath.h>
ShotSettings::ShotSettings(float yaw, float pitch, ProjectileKind _kind):projectile_kind(_kind)
{
	SetAzimuth(yaw);
	SetElevation(pitch);
}
void ShotSettings::RayVectorNormalize(Vector3& vector)
{
	float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	if (magnitude != 0)
		vector /= magnitude;
}
void ShotSettings::SetAzimuth(float angle)
{
	angle = angle * PI / 180;
	Matrix rotateMatrix = MatrixRotateY(angle);
	direction = Vector3(1) * rotateMatrix;

	RayVectorNormalize(direction);
}

void ShotSettings::ChangeAzimuth(float angle)
{
	angle = angle * PI / 180;
	Matrix rotateMatrix = MatrixRotateY(angle);
	direction *= rotateMatrix;

	RayVectorNormalize(direction);
}

void ShotSettings::SetElevation(float angle)
{
	angle = angle * PI / 180;
	Matrix rotateMatrix = MatrixRotateZ(angle);
	direction = Vector3(1) * rotateMatrix;

	RayVectorNormalize(direction);
	
}

void ShotSettings::ChangeElevation(float angle)
{
	angle = angle * PI / 180;
	Matrix rotateMatrix = MatrixRotateZ(angle);
	direction *= rotateMatrix;

	RayVectorNormalize(direction);
}

Vector3 ShotSettings::GetDirection()
{
	return direction;
}

Launcher::Launcher(float _yaw, float _pitch, float _rotation_speed, InputManager* _input) : shot_settings(_yaw, _pitch, ProjectileKind::Light), 
																							input(_input)
{
	yaw = _yaw;
	pitch = _pitch;
	rotation_speed = _rotation_speed;
	
}

void Launcher::SetYaw(float angle)
{
	yaw = angle;
	shot_settings.SetAzimuth(angle);
}

void Launcher::SetPitch(float angle)
{
	pitch = angle;
	shot_settings.SetAzimuth(angle);
}
void Launcher::ChangeYaw(float angle)
{
	yaw += angle;
	shot_settings.ChangeAzimuth(angle);

}
void Launcher::ChangePitch(float angle)
{
	pitch += angle;
	shot_settings.ChangeElevation(angle);
}
