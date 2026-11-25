#pragma once
#include "GameEntity.h"

class Projectile : public GameEntity
{
protected:

	cyclone::CollisionSphere m_sphere;

public:

	virtual const std::string getType() { return "Projectile"; }
	void draw() override;
	virtual void registerPhysics(/*world*/) = 0;
	void fire(/*settings*/);
};

