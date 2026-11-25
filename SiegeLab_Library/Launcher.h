#pragma once
#include "InputManager.h"
enum class ProjectileKind{Heavy, Light};
class ShotSettings
{
public:
	Vector3 origin;
	float projectile_speed = 0;
	ProjectileKind projectile_kind;
	ShotSettings(float yaw, float pitch, ProjectileKind _kind);
	void RayVectorNormalize(Vector3& vector);
	/// <summary>
	/// modifie le vecteur direction en ajoutent l'angle mis en paramètre. 
	/// </summary>
	/// <param name="angle">angle est en degré et il sera convertie en radians pour faire le vecteur direction</param>
	void SetAzimuth(float angle);

	/// <summary>
	/// modifie le vecteur direction en ajoutent l'angle mis en paramètre. 
	/// </summary>
	/// <param name="angle">angle est en degré et il sera convertie en radians pour faire le vecteur direction</param>
	void SetElevation(float angle);

	Vector3 GetDirection();
private:
	Vector3 direction{0,1,0};
};


class Launcher
{
public:
	Launcher(float _yaw = 0, float _pitch = 0, float _projectile_speed = 0, InputManager* input = nullptr);
	ShotSettings shot_settings;
	void SetYaw(float angle);
	void ChangeYaw(float angle);
	void SetPitch(float angle);
	void ChangePitch(float angle);

	float GetYaw();
	float GetPitch();
	float GetProjectileSpeed();
private:
	InputManager* input;
	float yaw = 0, yaw_min = -30, yaw_max = 30;
	float pitch = 0, pitch_min = 5, pitch_max = 55;
	float rotation_speed = 10;
	float projectile_speed, projectile_speed_min = 8, projectile_speed_max = 22;

	 
};

