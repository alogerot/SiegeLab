#include "pch.h"
#include "../SiegeLab_Library/OrbitCamera.h"
#include "../SiegeLab_Library/SceneObjects.h"
#include "../SiegeLab_Library/StandardProjectile.h"
#include "../SiegeLab_Library/HeavyProjectile.h"
#include <Launcher.h>

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
TEST(GP_M2, L01)
{
	Launcher launcher;
	launcher.SetYaw(0);
	launcher.SetPitch(30);
	EXPECT_NEAR(launcher.shot_settings.direction.z, 0.0, 1e-4);
}

TEST(GP_M2, L02)
{
	Launcher case1(30, 30, 8);
	Launcher case2(30, 45, 8);

	float magnitude1 = sqrt(case1.shot_settings.direction.x * case1.shot_settings.direction.x +
		case1.shot_settings.direction.y * case1.shot_settings.direction.y +
		case1.shot_settings.direction.z * case1.shot_settings.direction.z);
	float magnitude2 = sqrt(case2.shot_settings.direction.x * case2.shot_settings.direction.x +
		case2.shot_settings.direction.y * case2.shot_settings.direction.y +
		case2.shot_settings.direction.z * case2.shot_settings.direction.z);
	EXPECT_NEAR(magnitude1, 1, 1e-4);
	EXPECT_NEAR(magnitude2, 1, 1e-4);
}
TEST(GP_M2, L03)
{
	//(45°, −10°, 30 m / s)
	Launcher launcher(45, -10, 30);
	EXPECT_EQ(launcher.GetYaw(), 30);
	EXPECT_EQ(launcher.GetPitch(), 5);
	EXPECT_EQ(launcher.GetProjectileSpeed(), 22);
}
TEST(GP_M2, L04)
{
	Launcher launcher(20, 30, 8);
}

TEST(GP_M2, L05)
{
	InputManager input;
	Launcher launcher(20, 30, 8, &input, ProjectileKind::Light);
}
