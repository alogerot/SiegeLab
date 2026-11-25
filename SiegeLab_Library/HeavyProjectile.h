#pragma once
#include "Projectile.h"

class HeavyProjectile : public Projectile
{
public:
	HeavyProjectile() : Projectile() { m_sphere = cyclone::CollisionSphere(); }
	void registerPhysics(/*world*/) override;
	const std::string getType() override;
};

