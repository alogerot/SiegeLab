#pragma once
#include "Projectile.h"

class StandardProjectile : public Projectile
{

private:



public:
	StandardProjectile(base_transform_data);
	StandardProjectile(base_transform_data, Vector3);

	const std::string getType() override;
	void draw() override;
	void configurePhysics();
	void update(float dt) override
	{
		m_body.setAwake();
		if (m_body.getPosition().y > 0.28)
			m_body.addForce(cyclone::Vector3::GRAVITY);
		else
		{
			cyclone::Vector3 vel = m_body.getVelocity();
			vel.y = 0;
			m_body.setVelocity(vel);
		}
			
		m_body.integrate(dt);
	}
};

