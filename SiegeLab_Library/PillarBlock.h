#pragma once
#include "Block.h"


class PillarBlock : public Block
{
private:

	


public:
	PillarBlock(base_transform_data,block_data _data);
	void draw() override;
	void configurePhysics();
};

