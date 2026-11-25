#pragma once
#include "GameEntity.h"

struct block_data
{
	float height;
	float radius;
};

class Block : public GameEntity
{
protected:

	cyclone::CollisionBox m_collision_box;
	
public:

	virtual void draw() = 0;
	void registerPhysics(/*world*/) override;
};

