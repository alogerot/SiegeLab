#pragma once
#include "ObjectPool.h"
#include "GameEntity.h"

class SceneObjects
{
	ObjectPool<GameEntity, 10> m_obj_pool;




public:


	template<typename Type, typename... Args>
	EntityId create_Entity(Args&& ... _args);

	GameEntity* get(EntityId _id);

	void requestRemove(EntityId _id);

	void flushRemovals();
};


template<typename Type,typename... Args>
EntityId SceneObjects::create_Entity(Args&& ... _args)
{
	return m_obj_pool.create<Type>(std::forward<Args>(_args)...);
}

