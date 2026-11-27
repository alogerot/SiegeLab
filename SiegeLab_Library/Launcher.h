#pragma once
#include "InputManager.h"
#include "SceneObjects.h"

enum class ProjectileKind{Heavy, Light};
class ShotSettings
{
public:
	Vector3 origin;
	float projectile_speed = 0;
	ProjectileKind projectile_kind;
	ShotSettings();
	ShotSettings(ProjectileKind _kind);
	
	Vector3 direction{1,0,0};
private:
};


class Launcher
{
public:
	Launcher();
	Launcher(float _yaw, float _pitch, float _projectile_speed, InputManager* input = nullptr, ProjectileKind _kind = ProjectileKind::Light, SceneObjects* s = nullptr);
	ShotSettings shot_settings;
	void RayVectorNormalize(Vector3& vector);


	void SetYaw(float angle);
	void ChangeYaw(float angle);
	void SetAzimuth(float angle);

	void SetPitch(float angle);
	void ChangePitch(float angle);
	void SetElevation(float angle);

	float GetYaw();
	float GetPitch();
	float GetProjectileSpeed();

	

	void Update(float dt);

	void shoot(float dt);
private:

	float m_shoot_cd;
	SceneObjects* scene;
	InputManager* input;
	float yaw = 0, yaw_min = -30, yaw_max = 30;
	float pitch = 0, pitch_min = 5, pitch_max = 55;
	float rotation_speed = 10;
	float projectile_speed, projectile_speed_min = 8, projectile_speed_max = 22;

	 
};

