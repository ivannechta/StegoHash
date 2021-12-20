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

TEST(Write, s100m11) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.WriteToContainer("11"), "100"), 0);
	
}