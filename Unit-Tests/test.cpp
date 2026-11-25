#include "pch.h"
#include <Launcher.h>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
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
	EXPECT_NEAR(magnitude1,1,1e-4);
	EXPECT_NEAR(magnitude2,1,1e-4);
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