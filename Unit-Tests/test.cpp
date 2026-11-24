#include "pch.h"
#include "../SiegeLab_Library/OrbitCamera.h"
#include "../SiegeLab_Library/ObjectPool.h"

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

	pool.destroy({0,0});

	pool.create(42);

	//EXPECT_EQ(*pool.get({0,0}), 42);
	EXPECT_EQ(*pool.get({ 0,1 }), 42);
}


TEST(GP_T3, C01)
{
	placement p{ {2,1,0},10,0,20 };
	OrbitCamera camTest(p);



	//camTest.set_data(p);



	EXPECT_EQ(1, 1);
}
