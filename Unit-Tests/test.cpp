#include "pch.h"
#include "../SiegeLab_Library/OrbitCamera.h"
#include "../SiegeLab_Library/SceneObjects.h"
#include "../SiegeLab_Library/StandardProjectile.h"
#include "../SiegeLab_Library/HeavyProjectile.h"

TEST(GP_T1, P01) 
{
	ObjectPool<int,3> pool;
	pool.create<int>(10);
	pool.create<int>(20);
	pool.create<int>(30);
	pool.create<int>(40);



	EXPECT_EQ(*pool.get({0,0}), 10);
	EXPECT_EQ(*pool.get({1,0}), 20);
	EXPECT_EQ(*pool.get({2,0}), 30);
	//EXPECT_EQ(*pool.get(3), 40);
}

TEST(GP_T1, P02)
{
	ObjectPool<int, 1> pool;
	pool.create<int>(7);

	EXPECT_EQ(*pool.get({ 0,0 }), 7);

	pool.destroy({ 0,0 });

	pool.create<int>(42);

	EXPECT_EQ(*pool.get({ 0,1 }), 42);
}


TEST(GP_T1, P03)
{
	ObjectPool<int, 1> pool;
	pool.create<int>(7);

	EXPECT_EQ(*pool.get({ 0,0 }), 7);

	pool.destroy({0,0});

	pool.create<int>(42);

	EXPECT_EQ(pool.get({0,0}), nullptr);
	EXPECT_EQ(*pool.get({ 0,1 }), 42);
}

TEST(GP_T1, P04)
{
	ObjectPool<int, 3> pool;
	EntityId aId = pool.create<int>(10);

	int* p = pool.get(aId);

	pool.create<int>(20);
	pool.create<int>(30);

	EXPECT_EQ(*pool.get(aId), 10);
	EXPECT_EQ(*p, 10);
	EXPECT_EQ(pool.get(aId), p);

}

TEST(GP_T1, P05)
{
	ObjectPool<int, 2> pool;

	EntityId aId = pool.create<int>(10);
	EntityId bId = pool.create<int>(20);

	pool.clear();


	EXPECT_EQ(pool.get(aId), nullptr);
	EXPECT_EQ(pool.get(bId), nullptr);

	EntityId cId = pool.create<int>(30);

	EXPECT_EQ(*pool.get(cId), 30);
}


TEST(GP_T2, GO01)
{
	SceneObjects scene_object;
	EntityId id_Standard = scene_object.create_Entity<StandardProjectile>();
	EntityId id_Heavy = scene_object.create_Entity<HeavyProjectile>();

	EXPECT_EQ(scene_object.get(id_Standard)->getType(), "StandardProjectile");
	EXPECT_EQ(scene_object.get(id_Heavy)->getType(), "HeavyProjectile");
}


TEST(GP_T3, C01)
{
	placement p{ {2,1,0},10,0,20 };



	//camTest.set_data(p);



	EXPECT_EQ(1, 1);
}
