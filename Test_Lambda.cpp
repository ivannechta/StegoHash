#include "gtest/gtest.h"
#include "LambdaTable.h"

TEST(Convert, Dec2Bin_0) {
	Lambda L(3,13);
	
	EXPECT_EQ(strcmp(L.Dec2Bin(0), "0"),0);
	EXPECT_TRUE(true);
}
TEST(Convert, Dec2Bin_13) {
	Lambda L(3, 13);
	EXPECT_EQ(strcmp(L.Dec2Bin(13), "1101"), 0);
	EXPECT_TRUE(true);
}
TEST(Search, Code_25) {
	Lambda L(5, 61);	
	EXPECT_EQ(L.GetDByCode(new BitStr("1101")), 25);
	EXPECT_TRUE(true);
}
TEST(Search, Code_29) {
	Lambda L(5, 61);
	EXPECT_EQ(L.GetDByCode(new BitStr("11001")), 29);
	EXPECT_TRUE(true);
}
TEST(Search, D_0) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("0");
	BitStr* b = L.GetCodeByD(0);	
	EXPECT_EQ(*b == *a, true);
	EXPECT_TRUE(true);
}
TEST(Search, D_8) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("1110");
	BitStr* b = L.GetCodeByD(8);
	EXPECT_EQ(*b == *a, true);
	EXPECT_TRUE(true);
}
TEST(Search, D_29) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("11001");
	BitStr* b = L.GetCodeByD(29);	
	EXPECT_EQ(*b==*a, true);
	EXPECT_TRUE(true);
}