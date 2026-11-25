#include "SceneObjects.h"

int* SceneObjects::get(EntityId _id)
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