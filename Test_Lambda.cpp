#include "gtest/gtest.h"
#include "LambdaTable.h"

TEST(Convert, Dec2Bin_0) {
	Lambda L(2,13);
	
	EXPECT_EQ(strcmp(L.Dec2Bin(0), "0"),0);
	EXPECT_TRUE(true);
}
TEST(Convert, Dec2Bin_13) {
	Lambda L(2, 13);
	EXPECT_EQ(strcmp(L.Dec2Bin(13), "1101"), 0);
	EXPECT_TRUE(true);
}