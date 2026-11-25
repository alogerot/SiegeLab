#include "HeavyProjectile.h"


HeavyProjectile::HeavyProjectile()
{
	m_sphere.radius = 0.36;
}

void HeavyProjectile::registerPhysics()
{
}

const std::string HeavyProjectile::getType()
{
	return "HeavyProjectile";
}
