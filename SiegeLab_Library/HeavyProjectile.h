#pragma once
#include "Projectile.h"

class HeavyProjectile : public Projectile
{
public:
	HeavyProjectile();
	void registerPhysics(/*world*/) override;
	const std::string getType() override;
};

