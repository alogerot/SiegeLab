#include "pch.h"
#include <Launcher.h>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(GP_M2, L01)
{
	Launcher launcher;
	launcher.shot_settings.SetAzimuth(0);
	launcher.shot_settings.SetElevation(30);
	EXPECT_NEAR(launcher.shot_settings.GetDirection().z, 0.0, 1e-4);
}

TEST(GP_M2, L02)
{
	Launcher case1(30, 30);
	Launcher case2(30, 45);

	float magnitude1 = sqrt(case1.shot_settings.GetDirection().x * case1.shot_settings.GetDirection().x + 
							case1.shot_settings.GetDirection().y * case1.shot_settings.GetDirection().y +
							case1.shot_settings.GetDirection().z * case1.shot_settings.GetDirection().z);
	float magnitude2 = sqrt(case2.shot_settings.GetDirection().x * case2.shot_settings.GetDirection().x + 
							case2.shot_settings.GetDirection().y * case2.shot_settings.GetDirection().y +
							case2.shot_settings.GetDirection().z * case2.shot_settings.GetDirection().z);
	EXPECT_NEAR(magnitude1,1,1e-4);
	EXPECT_NEAR(magnitude2,1,1e-4);
}