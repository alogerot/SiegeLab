#pragma once
#include "Projectile.h"

class HeavyProjectile : public Projectile
{
public:
	HeavyProjectile();
	HeavyProjectile(base_transform_data, Vector3);
	void registerPhysics(/*world*/) override;
	const std::string getType() override;
};

