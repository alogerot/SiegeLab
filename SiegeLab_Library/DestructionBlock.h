#pragma once
#include "Block.h"
class DestructionBlock : public Block
{
private:
	cyclone::real breakThreshold;
public:
	DestructionBlock(base_transform_data, block_data _data, cyclone::real _breakThreshold = 0);
	void draw() override;
	void configurePhysics();
};

