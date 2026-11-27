#pragma once
#include "ObjectPool.h"
#include "GameEntity.h"


class Launcher;

class SceneObjects
{
	ObjectPool<GameEntity, 10> m_obj_pool;




public:

	SceneObjects();
	template<typename Type, typename... Args>
	EntityId create_Entity(Args&& ... _args);
	void setupCanon(Launcher* _launcher);
	GameEntity* get(EntityId _id);

	void requestRemove(EntityId _id);
	void flushRemovals();

	void drawAll();
	void updateAll(float dt);
};


template<typename Type,typename... Args>
EntityId SceneObjects::create_Entity(Args&& ... _args)
{
	return m_obj_pool.create<Type>(std::forward<Args>(_args)...);
}

