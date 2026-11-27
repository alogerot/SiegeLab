#include "Canon.h"
#include <raymath.h>

const std::string Canon::getType()
{
	return "Canon";
}

void Canon::draw()
{
	m_model.transform = MatrixRotateXYZ(Vector3{ 0, DEG2RAD * -m_launcher->GetYaw(), 0});
	m_tube_model.transform = MatrixRotateXYZ(Vector3{ DEG2RAD * m_launcher->GetPitch(),DEG2RAD * -m_launcher->GetYaw(),0 });
	Vector3 base_pos{ m_body.getPosition().x, m_body.getPosition().y, m_body.getPosition().z };
	DrawModel(m_model, base_pos, 1, BLACK);

	Vector3 tube_pos{ m_body.getPosition().x+0.2, m_body.getPosition().y+0.5, m_body.getPosition().z };
	DrawModelEx(m_tube_model, tube_pos, {0,1,0},90,{1,1,1}, GRAY);
}

Canon::Canon(base_transform_data _b_data, Launcher* _launcher)
{
	m_launcher = _launcher;
	m_model = LoadModelFromMesh(GenMeshCube(0.5, 0.5, 0.5));
	m_tube_model = LoadModelFromMesh(GenMeshCube(0.3, 1, 0.3));
	cyclone::Vector3 pos{ _b_data.position.x, _b_data.position.y, _b_data.position.z };
	cyclone::Vector3 rota{ _b_data.rotation.x, _b_data.rotation.y, _b_data.rotation.z };
	m_body.setPosition(pos);
	m_body.setRotation(rota);
}
