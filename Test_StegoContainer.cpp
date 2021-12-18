#include "gtest/gtest.h"
#include "StegoContainer.h"

TEST(Read, e101m11) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.WriteToContainer("11"),"100"),0);
	printf("Read(100) ->%s\n", s.ReadFromContainer("100"));
}
TEST(Write, s100m11) {
	StegoContainer s("101");
	EXPECT_EQ(strcmp(s.ReadFromContainer("100"), "11"), 0);	
}