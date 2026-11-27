#include "StandardProjectile.h"

StandardProjectile::StandardProjectile(base_transform_data _b_data)
{
	m_model = LoadModelFromMesh(GenMeshSphere(0.28, 10, 10));
	cyclone::Vector3 pos{ _b_data.position.x, _b_data.position.y, _b_data.position.z };
	cyclone::Vector3 rota{ _b_data.rotation.x, _b_data.rotation.y, _b_data.rotation.z };
	m_body.setPosition(pos);
	m_body.setRotation(rota);
	configurePhysics();
}

StandardProjectile::StandardProjectile(base_transform_data _b_data, Vector3 _initial_velocity)
{
	m_model = LoadModelFromMesh(GenMeshSphere(0.28, 10, 10));
	cyclone::Vector3 pos{ _b_data.position.x, _b_data.position.y, _b_data.position.z };
	cyclone::Vector3 rota{ _b_data.rotation.x, _b_data.rotation.y, _b_data.rotation.z };
	m_body.setPosition(pos);
	m_body.setRotation(rota);
	m_body.setVelocity(_initial_velocity.x, _initial_velocity.y, _initial_velocity.z);
	configurePhysics();
}

const std::string StandardProjectile::getType()
{
	return "StandardProjectile";
}

void StandardProjectile::draw()
{
	Vector3 pos{ m_body.getPosition().x, m_body.getPosition().y, m_body.getPosition().z };
	DrawModelEx(m_model, pos, Vector3{ 0.5f, 1.0f, 0.0f },
		0, Vector3{ 1.0f, 1.0f, 1.0f }, RED);
}

void StandardProjectile::configurePhysics()
{
	m_body.setMass(1);
	m_sphere.radius = 0.28;
	m_body.setDamping(0.8,0.8);
}




