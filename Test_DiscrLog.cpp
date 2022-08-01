#include "pch.h"
#include "Number.h"
#include "DiscrLog.h"

TEST(DiscrLog, a_12_mod_19) {
	Number a((char*)"100011");
	Number p((char*)"1010");

	DiscrLog d(a, p);
	d.Divide();
	EXPECT_EQ(d.GetPower(), 11);
}

TEST(DiscrLog, a_0_mod_7) {
	Number y((char*)"0");
	Number p((char*)"111");
	DiscrLog d(p,y);
	d.Divide();	
	EXPECT_EQ(d.GetPower(), -1);
}

TEST(DiscrLog, a_1_mod_7) {
	Number y((char*)"01");
	Number p((char*)"111");
	DiscrLog d(p, y);
	d.Divide();
	EXPECT_EQ(d.GetPower(), 0);
}

TEST(DiscrLog, a_replace_P_Y_throw) {
	Number y((char*)"01");
	Number p((char*)"111");
	DiscrLog d(y, p);	
	EXPECT_THROW(d.Divide(); , int);
}

TEST(DiscrLog, a_2_mod_7) {
	Number y((char*)"10");
	Number p((char*)"111");
	DiscrLog d(p,y);
	d.Divide();
	EXPECT_EQ(d.GetPower(), 1);
} 
TEST(DiscrLog, a_4_mod_7) {
	Number y((char*)"11");
	Number p((char*)"111");
	DiscrLog d(p,y);
	d.Divide();
	EXPECT_EQ(d.GetPower(), 2);
}




