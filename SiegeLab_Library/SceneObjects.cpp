#include "SceneObjects.h"
#include "Canon.h"

SceneObjects::SceneObjects()
{
    
}

void SceneObjects::setupCanon(Launcher* _launcher)
{
    create_Entity<Canon>(base_transform_data{ { -4,2,0} }, _launcher);
}

GameEntity* SceneObjects::get(EntityId _id)
{
    return m_obj_pool.get(_id);
}

void SceneObjects::requestRemove(EntityId _id)
{
    m_obj_pool.destroy(_id);
}

void SceneObjects::flushRemovals()
{
	m_obj_pool.clear();
}

void SceneObjects::drawAll()
{
    m_obj_pool.draw();
}

void SceneObjects::updateAll(float dt)
{
    m_obj_pool.update(dt);
}
