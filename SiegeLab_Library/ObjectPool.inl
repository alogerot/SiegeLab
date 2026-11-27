#include "ObjectPool.h"
#pragma once

template<typename Type, int max_size>
ObjectPool<Type, max_size>::ObjectPool()
{
	m_obj_Pool.resize(max_size);
	m_free_slots.reserve(max_size);
	for (int i = 0; i < max_size; ++i)
	{
		m_free_slots.push_back(i);
	}

}

template<typename Type, int max_size>
Type* ObjectPool<Type, max_size>::get(EntityId _id)
{
	if (_id.slot < 0 || _id.slot >= max_size || m_obj_Pool[_id.slot].generation != _id.generation)
		return nullptr;
	return  m_obj_Pool[_id.slot].data;
}

template<typename Type, int max_size>
void ObjectPool<Type, max_size>::destroy(EntityId _id)
{
	if (_id.slot < 0 || _id.slot >= max_size)
		return;
	m_free_slots.push_back(_id.slot);
	m_obj_Pool[_id.slot].generation++;
	m_obj_Pool[_id.slot].data = nullptr;
}

template<typename Type, int max_size>
void ObjectPool<Type, max_size>::clear()
{
	for (int i = 0;i < m_obj_Pool.size();i++)
	{
		delete m_obj_Pool[i].data;
		m_obj_Pool[i].data = nullptr;
		m_obj_Pool[i].generation++;
		m_free_slots.push_back(i);
	}
}

template<typename Type, int max_size>
inline void ObjectPool<Type, max_size>::draw()
{
	for (int i = 0; i < max_size; i++)
	{
		if (m_obj_Pool[i].data != nullptr)
			m_obj_Pool[i].data->draw();
	}
}

template<typename Type, int max_size>
inline void ObjectPool<Type, max_size>::update(float dt)
{
	for (int i = 0; i < max_size; i++)
	{
		if (m_obj_Pool[i].data != nullptr)
			m_obj_Pool[i].data->update(dt);
	}
}

template<typename Type, int max_size>
template<typename EntityType, typename... Args>
EntityId ObjectPool<Type, max_size>::create(Args&&... _args)
{
	if (m_free_slots.empty())
		return EntityId{ -1,-1 };
	int slot = m_free_slots.front();
	m_free_slots.erase(m_free_slots.begin());
	int generation = m_obj_Pool[slot].generation;
	m_obj_Pool[slot] = PoolSlot{ new EntityType(std::forward<Args>(_args)...), generation };

	return EntityId{ slot, generation };
}