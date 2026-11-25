#include "Launcher.h"
#include <raymath.h>
#include <algorithm>
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
	direction = direction * rotateMatrix;

	RayVectorNormalize(direction);
}

void ShotSettings::SetElevation(float angle)
{
	angle = angle * PI / 180;
	Matrix rotateMatrix = MatrixRotateZ(angle);
	direction = direction * rotateMatrix;

	RayVectorNormalize(direction);
	
}


Vector3 ShotSettings::GetDirection()
{
	return direction;
}

Launcher::Launcher(float _yaw, float _pitch, float _projectile_speed, InputManager* _input) : shot_settings(0, 0, ProjectileKind::Light),
																							input(_input)
{
	
	SetYaw(std::clamp(_yaw, yaw_min, yaw_max));
	SetPitch(std::clamp(_pitch, pitch_min, pitch_max));

	projectile_speed = std::clamp(_projectile_speed, projectile_speed_min, projectile_speed_max);
	
}

void Launcher::SetYaw(float angle)
{
	float tmp = yaw;
	yaw = std::clamp(angle, yaw_min, yaw_max);
	shot_settings.SetAzimuth(yaw - tmp);
}

void Launcher::SetPitch(float angle)
{
	float tmp = pitch;
	pitch = std::clamp(angle, pitch_min, pitch_max);
	shot_settings.SetAzimuth(pitch - tmp);
}
void Launcher::ChangeYaw(float angle)
{
	float tmp = yaw;
	yaw = std::clamp(yaw+angle, yaw_min, yaw_max);
	shot_settings.SetAzimuth(yaw - tmp);

}
void Launcher::ChangePitch(float angle)
{
	float tmp = pitch;
	pitch = std::clamp(pitch + angle, pitch_min, pitch_max);
	shot_settings.SetElevation(pitch - tmp);
}

float Launcher::GetYaw()
{
	return yaw;
}

float Launcher::GetPitch()
{
	return pitch;
}
float Launcher::GetProjectileSpeed()
{
	return projectile_speed;
}