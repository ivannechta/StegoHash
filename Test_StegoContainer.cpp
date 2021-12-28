#include "gtest/gtest.h"
#include "StegoContainer.h"

TEST(Read, e111m00) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.ReadFromContainer("111"), "00"), 0);
}
TEST(Read, e001m01) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.ReadFromContainer("001"), "01"), 0);
}
TEST(Read, e101m10) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.ReadFromContainer("101"), "10"), 0);
}
TEST(Read, e100m11) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.ReadFromContainer("100"), "11"), 0);
}

TEST(Write, s111m00) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.WriteToContainer("00"), "111"), 0);	
}
TEST(Write, s001m01) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.WriteToContainer("01"), "001"), 0);
}
TEST(Write, s101m10) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.WriteToContainer("10"), "101"), 0);
}
TEST(Write, s100m11) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.WriteToContainer("11"), "100"), 0);
}
TEST(Write, Complex7) {
	StegoContainer s("1111111");	
	EXPECT_EQ(strcmp(s.WriteToContainer("000"), "1111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("001"), "1111110"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("010"), "1111101"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("011"), "1011111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("100"), "1111011"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("101"), "1110111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("110"), "0111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("111"), "1101111"), 0);
}
TEST(Write, Complex15) {
	StegoContainer s("111111111111111");
	EXPECT_EQ(strcmp(s.WriteToContainer("0000"), "111111111111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("0001"), "111111111111110"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("0010"), "111111111111101"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("0011"), "111111111101111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("0100"), "111111111111011"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("0101"), "111111011111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("0110"), "111111111011111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("0111"), "111101111111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1000"), "111111111110111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1001"), "011111111111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1010"), "111110111111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1011"), "111111101111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1100"), "111111110111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1101"), "101111111111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1110"), "111011111111111"), 0);
	EXPECT_EQ(strcmp(s.WriteToContainer("1111"), "110111111111111"), 0);	
}


TEST(Read, Complex7) {
	StegoContainer s("1111111");
	EXPECT_EQ(strcmp("000", s.ReadFromContainer("1111111")), 0);
	EXPECT_EQ(strcmp("001", s.ReadFromContainer("1111110")), 0);
	EXPECT_EQ(strcmp("010", s.ReadFromContainer("1111101")), 0);
	EXPECT_EQ(strcmp("011", s.ReadFromContainer("1011111")), 0);
	EXPECT_EQ(strcmp("100", s.ReadFromContainer("1111011")), 0);
	EXPECT_EQ(strcmp("101", s.ReadFromContainer("1110111")), 0);
	EXPECT_EQ(strcmp("110", s.ReadFromContainer("0111111")), 0);
	EXPECT_EQ(strcmp("111", s.ReadFromContainer("1101111")), 0);
}
TEST(Read, Complex15) {
	StegoContainer s("111111111111111");
	EXPECT_EQ(strcmp("0000", s.ReadFromContainer("111111111111111")), 0);
	EXPECT_EQ(strcmp("0001", s.ReadFromContainer("111111111111110")), 0);
	EXPECT_EQ(strcmp("0010", s.ReadFromContainer("111111111111101")), 0);
	EXPECT_EQ(strcmp("0011", s.ReadFromContainer("111111111101111")), 0);
	EXPECT_EQ(strcmp("0100", s.ReadFromContainer("111111111111011")), 0);
	EXPECT_EQ(strcmp("0101", s.ReadFromContainer("111111011111111")), 0);
	EXPECT_EQ(strcmp("0110", s.ReadFromContainer("111111111011111")), 0);
	EXPECT_EQ(strcmp("0111", s.ReadFromContainer("111101111111111")), 0);
	EXPECT_EQ(strcmp("1000", s.ReadFromContainer("111111111110111")), 0);
	EXPECT_EQ(strcmp("1001", s.ReadFromContainer("011111111111111")), 0);
	EXPECT_EQ(strcmp("1010", s.ReadFromContainer("111110111111111")), 0);
	EXPECT_EQ(strcmp("1011", s.ReadFromContainer("111111101111111")), 0);
	EXPECT_EQ(strcmp("1100", s.ReadFromContainer("111111110111111")), 0);
	EXPECT_EQ(strcmp("1101", s.ReadFromContainer("101111111111111")), 0);
	EXPECT_EQ(strcmp("1110", s.ReadFromContainer("111011111111111")), 0);
	EXPECT_EQ(strcmp("1111", s.ReadFromContainer("110111111111111")), 0);
}

