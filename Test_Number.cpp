#include "pch.h"
#include "DiscrLog.h"

TEST(Constructor, EqualNum) {
	EXPECT_EQ(Number((char*)"0010") == Number((char*)"0010"), true);
	EXPECT_EQ(Number((char*)"0010") == Number((char*)"0100"), false);
	EXPECT_EQ(Number((char*)"0010") == Number((char*)"010"), false);
}

TEST(Constructor, Throw) {
	ASSERT_THROW(Number((char*)""), int);
}

TEST(AsArray, GetDigit) {
	Number a((char*)"0");
	Number b((char*)"1");
	Number c((char*)"10");
	Number d((char*)"11");
	EXPECT_EQ(a[0], 0);
	EXPECT_EQ(b[0], 1);
	EXPECT_EQ(c[0], 1);
	EXPECT_EQ(d[1], 1);
	EXPECT_EQ(a[1], -1);
}

TEST(Shift, Shift) {
	Number a((char*)"0");
	a << 1;
	EXPECT_EQ(a == Number((char*)"01"), true);
	a << 0;
	EXPECT_EQ(a == Number((char*)"010"), true);
	a << 1;
	EXPECT_EQ(a == Number((char*)"0101"), true);
}

TEST(Mul, AddZero) {
	Number a((char*)"1");
	a * 1;
	EXPECT_EQ(a == Number((char*)"1"), true);
	a * 3;
	EXPECT_EQ(a == Number((char*)"001"), true);
	a << 1;
	a * 5;
	EXPECT_EQ(a == Number((char*)"00011"), true);
	a * 3;
	EXPECT_EQ(a == Number((char*)"00011"), true);
}

TEST(Shift, Neg) {
	Number a((char*)"0");
	a << 1;
	EXPECT_EQ(a != Number((char*)"01"), false);
	a << 0;
	EXPECT_EQ(a != Number((char*)"110"), true);
	a << 1;
	EXPECT_EQ(a != Number((char*)"0101"), false);
}

TEST(Add, Throw) {
	Number a((char*)"0000");
	Number b((char*)"011");
	ASSERT_THROW(a + b, int);
}

TEST(Add, Equal) {
	Number a((char*)"1010");
	Number b((char*)"1010");
	EXPECT_EQ((a + b) == Number((char*)"0000"), true);
}

TEST(Add, Diff) {
	Number a((char*)"0000");
	Number b((char*)"1111");
	EXPECT_EQ((a + b) == Number((char*)"1111"), true);
}

TEST(Shift, Back) {
	Number a((char*)"0011");
	Number b((char*)"11000");
	EXPECT_EQ( (a>>5)== Number((char*)"11000"), true);
}

TEST(Shift, Back_Zero) {
	Number a((char*)"0000");		
	ASSERT_THROW(a >> 5, int);		
}
TEST(Shift, Back_Trunc) {
	Number a((char*)"1000");
	EXPECT_EQ((a >> 3) == Number((char*)"100"), true);
}

TEST(Assign, simple) {
	Number a((char*)"0011");
	Number b;
	b = a;
	EXPECT_EQ(b == a, true);
}
TEST(Assign, NonZero) {
	Number a((char*)"0010");
	Number b((char*)"1000");
	b = a;
	EXPECT_EQ(b == Number((char*)"0010"), true);
}

TEST(Compare, Compare) {
	Number a((char*)"100");Number b((char*)"1000");		
	EXPECT_EQ(a < b, true);
	EXPECT_EQ((b < a), false);
	
	Number c((char*)"111"); Number d((char*)"111");
	EXPECT_EQ(c < d, false);
	EXPECT_EQ(d < c, false);

	Number e((char*)"1"); Number f((char*)"0000");
	EXPECT_EQ(f < e, true);
	EXPECT_EQ(e < f, false);
	EXPECT_EQ(e < e, false);		
}



TEST(Compact, Compact) {
	Number a((char*)"0011");		
	-a;
	EXPECT_EQ(a==Number((char*)"11"), true);

	Number b((char*)"1011");
	-b;
	EXPECT_EQ(b == Number((char*)"1011"), true);

	Number c((char*)"000");
	-c;
	EXPECT_EQ(c == Number((char*)"0"), true);

	Number d((char*)"0");
	-d;
	EXPECT_EQ(d == Number((char*)"0"), true);

	Number e((char*)"1");
	-e;
	EXPECT_EQ(e == Number((char*)"1"), true);
}

