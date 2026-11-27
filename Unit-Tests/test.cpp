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
	placement p;
	p.target = { 2,1,0 };
	p.pitch = 20;
	p.yaw = 0;
	p.radius = 10;
	Camera3D cam;
	OrbitCamera camera(p);
	camera.update(nullptr, 1 / 60, cam);
	EXPECT_NEAR(cam.position.x, 2, 1e-3);
	EXPECT_NEAR(cam.position.y, 4.4202, 1e-3);
	EXPECT_NEAR(cam.position.z, 9.3969, 1e-3);

	p.yaw = 90;
	p.pitch = 30;
	camera.set_data(p);
	camera.update(nullptr, 1 / 60, cam);
	EXPECT_NEAR(cam.position.x, 10.6603, 1e-3);
	EXPECT_NEAR(cam.position.y, 6, 1e-3);
	EXPECT_NEAR(cam.position.z, 0, 1e-3);
	Vector3 delta = { cam.position.x - cam.target.x,
					cam.position.y - cam.target.y,
					cam.position.z - cam.target.z  };
	float distance = sqrt(delta.x * delta.x +
						delta.y * delta.y +
						delta.z * delta.z);
	EXPECT_EQ(distance, 10);
}
TEST(GP_T3, C02)
{
	placement p({ 0.f, 10.f, 10.f }, { 0.f, 0.f, 0.f }, 10.f, 4.f, 25.f, 3.f, 1.5f, 10.f, 80.f);
	p.pitch = -30;
	p.radius = 2;
	Camera3D cam;
	OrbitCamera camera(p);
	camera.update(nullptr, 1/60, cam);
	EXPECT_EQ(camera.GetRadius(), p.min_radius);
	EXPECT_EQ(camera.GetPitch(), p.min_pitch);
	p.pitch = 100;
	p.radius = 40;
	camera.set_data(p);
	camera.update(nullptr, 1/60, cam);
	EXPECT_EQ(camera.GetRadius(), p.max_radius);
	EXPECT_EQ(camera.GetPitch(), p.max_pitch);


}
TEST(GP_T3, C03)
{
	placement p({ 0,0,0 }, { 0,0,0 }, 10, 0, 100, 0, 0, 0, 100);
	p.yaw = 30;
	p.pitch = 20;
	Camera3D cam;
	OrbitCamera camera(p);
	camera.update(nullptr, 1 / 60, cam);
	EXPECT_NEAR(cam.position.x, 4.6985,1e-4);
	EXPECT_NEAR(cam.position.y, 3.4202,1e-4);
	EXPECT_NEAR(cam.position.z, 8.1380,1e-4);
	p.yaw = 390;
	camera.set_data(p);
	camera.update(nullptr, 1 / 60, cam);
	EXPECT_NEAR(cam.position.x, 4.6985, 1e-4);
	EXPECT_NEAR(cam.position.y, 3.4202, 1e-4);
	EXPECT_NEAR(cam.position.z, 8.1380, 1e-4);
}
TEST(GP_T3, C04)
{
	placement p({ 0,0,0 }, { 0,0,0 }, 10, 0, 100, 0, 90, 0, 100);
	p.pitch = 0;
	p.yaw = 0;
	InputManager input;
	input.keys_down[KEY_RIGHT] = true;
	input.mouse_button_down[MOUSE_BUTTON_RIGHT] = false;
	Camera3D cam;
	OrbitCamera camera(p);
	camera.update(&input, 0.5, cam);
	EXPECT_NEAR(camera.GetYaw(), 45, 1e-3);
	EXPECT_NEAR(cam.position.x, 7.0711, 1e-3);
	EXPECT_NEAR(cam.position.y, 0, 1e-3);
	EXPECT_NEAR(cam.position.z, 7.0711, 1e-3);

	camera.set_data(p);
	camera.update(&input, 0.25, cam);
	camera.update(&input, 0.25, cam);
	EXPECT_NEAR(camera.GetYaw(), 45, 1e-3);
	EXPECT_NEAR(cam.position.x, 7.0711, 1e-3);
	EXPECT_NEAR(cam.position.y, 0, 1e-3);
	EXPECT_NEAR(cam.position.z, 7.0711, 1e-3);
}
TEST(GP_T3, C05)
{
	placement p({ 0,0,0 }, { 0,0,0 }, 10, 0, 100, 0, 4, 0, 100);
	p.pitch = 0;
	p.yaw = 0;
	InputManager input;
	input.mouse_delta = { -2*60,0 };
	Camera3D cam;
	OrbitCamera camera(p);
	camera.update(&input, 1/60, cam);
	EXPECT_NEAR(camera.GetYaw(), 30, 1e-3);
	EXPECT_NEAR(cam.position.x, 5, 1e-3);
	EXPECT_NEAR(cam.position.y, 0, 1e-3);
	EXPECT_NEAR(cam.position.z, 8.6603, 1e-3);
	camera.set_data(p);
	input.mouse_delta = { -4 * 30,0 };
	camera.update(&input, 1 / 30, cam);
	EXPECT_NEAR(camera.GetYaw(), 30, 1e-3);
	EXPECT_NEAR(cam.position.x, 5, 1e-3);
	EXPECT_NEAR(cam.position.y, 0, 1e-3);
	EXPECT_NEAR(cam.position.z, 8.6603, 1e-3);
}
TEST(GP_T3, C06)
{

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
