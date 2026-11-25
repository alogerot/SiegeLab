#include "PillarBlock.h"

PillarBlock::PillarBlock(base_transform_data _b_data,block_data _data)
{

	m_model = LoadModelFromMesh(GenMeshCube(_data.radius, _data.height, _data.radius));
	cyclone::Vector3 pos{ _b_data.position.x, _b_data.position.y, _b_data.position.z };
	cyclone::Vector3 rota{ _b_data.rotation.x, _b_data.rotation.y, _b_data.rotation.z };
	m_collision_box.halfSize = pos * 0.5;
	m_body.setPosition(pos);
	m_body.setRotation(rota);
	configurePhysics();
}

void PillarBlock::draw()
{
	Vector3 pos{ m_body.getPosition().x, m_body.getPosition().y, m_body.getPosition().z };
	DrawModelEx(m_model, pos, Vector3{0.5f, 1.0f, 0.0f},
		0, Vector3{1.0f, 1.0f, 1.0f}, RED);
}

void PillarBlock::configurePhysics()
{
	m_body.setMass(3);
}

