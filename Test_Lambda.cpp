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
/*
TEST(Search, D_0) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("0");
	BitStr* b = L.GetCodeByD(0);	
	EXPECT_EQ(*b == *a, true);
	EXPECT_TRUE(true);
}
/*
TEST(Search, D_8) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("1110");
	BitStr* b = L.GetCodeByD(8);
	EXPECT_EQ(*b == *a, true);
	EXPECT_TRUE(true);a
}
TEST(Search, D_29) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("11001");
	BitStr* b = L.GetCodeByD(29);	
	EXPECT_EQ(*b==*a, true);
	EXPECT_TRUE(true);
}
*/
TEST(SearchFL, D_0) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("0");
	BitStr* tmp = new BitStr("0");
	BitStr* b = L.FLambda(tmp);
	EXPECT_EQ(*b == *a, true);
	EXPECT_TRUE(true);
}
TEST(SearchFL, D_8) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("1110");
	BitStr* tmp = new BitStr("10000000");
	BitStr* b = L.FLambda(tmp);
	EXPECT_EQ(*b == *a, true);
	EXPECT_TRUE(true);
}
TEST(SearchFL, D_29) {
	Lambda L(5, 61);
	BitStr* a = new BitStr("11001");
	BitStr* tmp = new BitStr("10000000000000000000000000000");
	BitStr* b = L.FLambda(tmp);
	EXPECT_EQ(*b == *a, true);
	EXPECT_TRUE(true);
}