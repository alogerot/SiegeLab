#pragma once
#include "GameEntity.h"




class Projectile : public GameEntity
{
protected:

	cyclone::CollisionSphere m_sphere;

public:

	virtual const std::string getType() { return "Projectile"; }
	void registerPhysics(/*world*/) override;
	
};

