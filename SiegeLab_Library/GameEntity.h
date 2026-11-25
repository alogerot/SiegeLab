#pragma once
#include <cyclone/body.h>
#include <cyclone/collide_fine.h>
#include <cyclone/contacts.h>
#include <string>

class GameEntity
{
private:

	cyclone::RigidBody m_body;

public:


	virtual const std::string getType() { return "GameEntity"; }
	virtual void draw() = 0;
	virtual void registerPhysics(/*world*/) = 0;
};

