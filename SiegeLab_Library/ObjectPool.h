#pragma once
#include <vector>
#include <memory>

template<typename Type>
struct EntityId
{
	Type slot;
	int generation;
};
template<typename Type>
class ObjectPool
{
private:

	EntityId m_obj_Pool[];
	int m_actual_id = 0;
	int m_max_capacity;

public:
	ObjectPool(int _capacity = 3);
	void create();
	Type get(int id);
	void destroy(int id);
	void clear();
};



template<typename Type>
ObjectPool<Type>::ObjectPool(int _capacity)
{
	m_obj_Pool = new Type[_capacity];
	m_max_capacity = _capacity;
}

template<typename Type>
void ObjectPool<Type>::create()
{
	if (m_actual_id < m_max_capacity)
		return;
	m_obj_Pool[m_actual_id] = new Type();
	m_actual_id++;
}


#include "ObjectPool.inl"