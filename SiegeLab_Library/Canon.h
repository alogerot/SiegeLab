#pragma once
#include "GameEntity.h"
#include "Launcher.h"

class Canon : public GameEntity
{
private:

	Model m_tube_model;
	Launcher* m_launcher;

public:


	const std::string getType() override;
	void draw() override;
	void update(float dt)override
	{
		return;
	}
	void registerPhysics() override {}
	void setLauncher(Launcher* l) { m_launcher = l; }
	Canon(base_transform_data, Launcher* _launcher);
};

