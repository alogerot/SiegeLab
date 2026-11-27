#pragma once
#include <cyclone/body.h>
#include <cyclone/collide_fine.h>
#include <cyclone/contacts.h>
#include <string>
#include <raylib.h>

struct base_transform_data
{
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	base_transform_data(
		Vector3 _pos = { 0.f,0.f,0.f }, 
		Vector3 _rota = { 0.f,0.f,0.f }, 
		Vector3 _scale = { 1.f,1.f,1.f })
	{
		position = _pos;
		rotation = _rota;
		scale = _scale;
	}
};


class GameEntity
{
protected:

	cyclone::RigidBody m_body;

	Model m_model;

public:
	virtual const std::string getType() { return "GameEntity"; }
	virtual void draw() = 0;
	virtual void registerPhysics(/*world*/) = 0;
	virtual void update(float dt) = 0;
	base_transform_data getTransform()
	{
		Vector3 pos(m_body.getPosition().x, m_body.getPosition().y, m_body.getPosition().z);
		return base_transform_data{ pos };
	}
	
};

