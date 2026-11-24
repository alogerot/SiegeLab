#include "pch.h"
#include "../SiegeLab_Library/OrbitCamera.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}



TEST(GP_T3, C01)
{
	placement p{ {2,1,0},10,0,20 };
	OrbitCamera camTest(p);



	//camTest.set_data(p);



	EXPECT_EQ(1, 1);
}
