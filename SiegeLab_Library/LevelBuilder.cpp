#include "LevelBuilder.h"
#include "PillarBlock.h"
#include "CubeBlock.h"
#include "DestructionBlock.h"

void LevelBuilder::buildPillarCube(SceneObjects& _s)
{
	_s.create_Entity<PillarBlock>(base_transform_data{ {0.f,1.5f,0.f} }, block_data{ 3,1 });
	_s.create_Entity<CubeBlock>(base_transform_data{ {0.f,3.5f,0.f} }, 1);
}

void LevelBuilder::BuildDestructionCage(SceneObjects& _s)
{
	_s.create_Entity<DestructionBlock>(base_transform_data{ {0.f,1.5f,0.f} }, block_data{ 3,1 }, 3);
}
