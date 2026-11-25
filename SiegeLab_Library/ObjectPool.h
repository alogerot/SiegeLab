#pragma once
#include <vector>

struct EntityId
{
	int slot;
	int generation;
};



template<typename Type, int max_size>
class ObjectPool
{
	
	struct PoolSlot
	{
		Type* data;
		int generation;
	};

private:

	std::vector<PoolSlot> m_obj_Pool;
	std::vector<int> m_free_slots;

public:
	ObjectPool();
	template<typename EntityType, typename... Args>
	EntityId create(Args&&... _args);


	Type* get(EntityId _id);
	void destroy(EntityId _id);
	void clear();
	void draw();
};



#include "ObjectPool.inl"