#include "pch.h"
#include "../SiegeLab_Library/OrbitCamera.h"
#include "../SiegeLab_Library/SceneObjects.h"

TEST(GP_T1, P01) 
{
	ObjectPool<int,3> pool;
	pool.create(10);
	pool.create(20);
	pool.create(30);
	pool.create(40);



	EXPECT_EQ(*pool.get({0,0}), 10);
	EXPECT_EQ(*pool.get({1,0}), 20);
	EXPECT_EQ(*pool.get({2,0}), 30);
	//EXPECT_EQ(*pool.get(3), 40);
}

TEST(GP_T1, P02)
{
	ObjectPool<int, 1> pool;
	pool.create(7);

	EXPECT_EQ(*pool.get({ 0,0 }), 7);

	pool.destroy({ 0,0 });

	pool.create(42);

	EXPECT_EQ(*pool.get({ 0,1 }), 42);
}


TEST(GP_T1, P03)
{
	ObjectPool<int, 1> pool;
	pool.create(7);

	EXPECT_EQ(*pool.get({ 0,0 }), 7);

	pool.destroy({0,0});

	pool.create(42);

	EXPECT_EQ(pool.get({0,0}), nullptr);
	EXPECT_EQ(*pool.get({ 0,1 }), 42);
}

TEST(GP_T1, P04)
{
	ObjectPool<int, 3> pool;
	EntityId aId = pool.create(10);

	int* p = pool.get(aId);

	pool.create(20);
	pool.create(30);

	EXPECT_EQ(*pool.get(aId), 10);
	EXPECT_EQ(*p, 10);
	EXPECT_EQ(pool.get(aId), p);

}

TEST(GP_T1, P05)
{
	ObjectPool<int, 2> pool;

	EntityId aId = pool.create(10);
	EntityId bId = pool.create(20);

	pool.clear();


	EXPECT_EQ(pool.get(aId), nullptr);
	EXPECT_EQ(pool.get(bId), nullptr);

	EntityId cId = pool.create(30);

	EXPECT_EQ(*pool.get(cId), 30);
}


TEST(OWN, test1)
{
	SceneObjects scene_object;
	EntityId id = scene_object.create_Entity(10);

	int* data = scene_object.get(id);

	EXPECT_EQ(*data, 10);
}


TEST(GP_T3, C01)
{
	placement p{ {2,1,0},10,0,20 };
	OrbitCamera camTest(p);



	//camTest.set_data(p);



	EXPECT_EQ(1, 1);
}
