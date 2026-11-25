#pragma once
#include "GameEntity.h"

class Projectile : public GameEntity
{
protected:

	cyclone::CollisionSphere m_sphere;

public:

	virtual const std::string getType() { return "Projectile"; }
	virtual void draw() = 0;
	virtual void registerPhysics() = 0;
	void fire(/*settings*/);
};

