#pragma once
#include "ObjectPool.h"


class SceneObjects
{
	ObjectPool<int/*GameEntity*/, 10> m_obj_pool;




public:


	template<typename... Args>
	EntityId create_Entity(Args&& ... _args);

	int/*GameEntity*/* get(EntityId _id);

	void requestRemove(EntityId _id);

	void flushRemovals();
};


template<typename... Args>
EntityId SceneObjects::create_Entity(Args&& ... _args)
{
	return m_obj_pool.create(std::forward<Args>(_args)...);
}

