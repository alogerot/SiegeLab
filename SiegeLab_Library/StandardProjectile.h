#pragma once
#include "Projectile.h"

class StandardProjectile : public Projectile
{


public:
	StandardProjectile() : Projectile() { m_sphere = cyclone::CollisionSphere(); }

	const std::string getType() override;

	void registerPhysics(/*world*/) override;
};

