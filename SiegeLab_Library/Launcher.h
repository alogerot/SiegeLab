#pragma once
#include "InputManager.h"
enum class ProjectileKind{Heavy, Light};
class ShotSettings
{
public:
	Vector3 origin;
	float ProjectileSpeed = 0;
	ProjectileKind projectile_kind;
	ShotSettings(float yaw, float pitch, ProjectileKind _kind);
	void RayVectorNormalize(Vector3& vector);
	/// <summary>
	/// modifie le vecteur direction en changeant l'azimute. 
	/// </summary>
	/// <param name="angle">angle est en degré et il sera convertie en radians pour le stocker dans direction</param>
	void SetAzimuth(float angle);
	void ChangeAzimuth(float angle);

	/// <summary>
	/// modifie le vecteur direction en changeant l'élevation. 
	/// </summary>
	/// <param name="angle">angle est en degré et il sera convertie en radians pour le stocker dans direction</param>
	void SetElevation(float angle);
	void ChangeElevation(float angle);

	Vector3 GetDirection();
private:
	Vector3 direction;
};


class Launcher
{
public:
	Launcher(float _yaw = 0, float _pitch = 0, float _rotation_speed = 0, InputManager* input = nullptr);
	ShotSettings shot_settings;
	void SetYaw(float angle);
	void ChangeYaw(float angle);
	void SetPitch(float angle);
	void ChangePitch(float angle);


private:
	InputManager* input;
	float yaw;
	float pitch;
	float rotation_speed;
};

