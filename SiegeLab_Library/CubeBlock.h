#pragma once
#include "Block.h"

class CubeBlock : public Block
{
private:




public:
	CubeBlock(base_transform_data, float _size);
	void draw() override;
	void configurePhysics();
};


