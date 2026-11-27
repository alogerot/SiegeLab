#pragma once
#include "Projectile.h"

class StandardProjectile : public Projectile
{

private:



public:
	StandardProjectile(base_transform_data);

	const std::string getType() override;
	void draw() override;
	void configurePhysics();
};

