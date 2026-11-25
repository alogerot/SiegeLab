#include "Launcher.h"
#include <raymath.h>
#include <algorithm>
ShotSettings::ShotSettings()
{
}
ShotSettings::ShotSettings(ProjectileKind _kind):projectile_kind(_kind)
{
	
}
void Launcher::RayVectorNormalize(Vector3& vector)
{
	float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	if (magnitude != 0)
		vector /= magnitude;
}
void Launcher::SetAzimuth(float angle)
{
	angle = angle * PI / 180;
	Matrix rotateMatrix = MatrixRotateY(angle);
	
	shot_settings.direction *= rotateMatrix;

	RayVectorNormalize(shot_settings.direction);
}

void Launcher::SetElevation(float angle)
{
	angle = angle * PI / 180;
	Matrix rotateMatrix = MatrixRotateZ(angle);
	shot_settings.direction *= rotateMatrix;

	RayVectorNormalize(shot_settings.direction);
	
}


Launcher::Launcher() :input(nullptr), projectile_speed(0)
{
}

Launcher::Launcher(float _yaw, float _pitch, float _projectile_speed, InputManager* _input, ProjectileKind kind) : shot_settings(kind),
																							input(_input)
{
	
	SetYaw(_yaw);
	SetPitch(_pitch);

	projectile_speed = std::clamp(_projectile_speed, projectile_speed_min, projectile_speed_max);
	
}

void Launcher::SetYaw(float angle)
{
	float tmp = yaw;
	yaw = std::clamp(angle, yaw_min, yaw_max);
	SetAzimuth(yaw - tmp);
}

void Launcher::SetPitch(float angle)
{
	float tmp = pitch;
	pitch = std::clamp(angle, pitch_min, pitch_max);
	SetElevation(pitch - tmp);
}
void Launcher::ChangeYaw(float angle)
{
	float tmp = yaw;
	yaw = std::clamp(yaw+angle, yaw_min, yaw_max);
	SetAzimuth(yaw - tmp);

}
void Launcher::ChangePitch(float angle)
{
	float tmp = pitch;
	pitch = std::clamp(pitch + angle, pitch_min, pitch_max);
	SetElevation(pitch - tmp);
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

void Launcher::Update(float dt)
{
	if (input == nullptr)
		return;
	if (input->keys_down[KEY_Q])
		ChangeYaw(-rotation_speed * dt);
	if (input->keys_down[KEY_D])
		ChangeYaw(rotation_speed * dt);
	if (input->keys_down[KEY_S])
		ChangePitch(-rotation_speed * dt);
	if (input->keys_down[KEY_Z])
		ChangePitch(rotation_speed * dt);
	if (input->keys_down[KEY_A])
		shot_settings.projectile_speed -= 4 * dt;
	if (input->keys_down[KEY_E])
		shot_settings.projectile_speed += 4 * dt;
	if (input->keys_down[KEY_ONE])
		shot_settings.projectile_kind = ProjectileKind::Light;
	if (input->keys_down[KEY_TWO])
		shot_settings.projectile_kind = ProjectileKind::Heavy;

}
