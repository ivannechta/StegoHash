//#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING  1
#include "gtest/gtest.h"
#include "BitStr.h"
#include "Number.h"

	TEST(Constructor, FirstZero4)
	{
		BitStr C("0101");
		BitStr R("101");
		EXPECT_EQ(C == R, true);
	}

	TEST(Constructor, FirstZero1z)
	{
		BitStr C("0");
		BitStr R("0");
		EXPECT_EQ(C == R, true);
	}
	TEST(Constructor, FirstZero4e)
	{
		BitStr C("1010");
		BitStr R("1010");
		EXPECT_EQ(C == R, true);
	}
	TEST(Equality, OneBitEq)
	{
		BitStr A("0");
		BitStr B("0");
		EXPECT_EQ(A == B, true);
	}
	TEST(Equality, OneBitNeq)
	{
		BitStr A("0");
		BitStr B("1");
		EXPECT_EQ(A == B, false);
	}
	TEST(NonEquality, OneBitEq)
	{
		BitStr A("0");
		BitStr B("0");
		EXPECT_EQ(A != B, false);
	}
	TEST(NonEquality, OneBitNeq)
	{
		BitStr A("0");
		BitStr B("1");
		EXPECT_EQ(A != B, true);
	}
	TEST(Equality, SeveralBitEq)
	{
		BitStr A("101010");
		BitStr B("101010");
		EXPECT_EQ(A == B, true);
	}
	TEST(Operator, AsArray)
	{
		const char* s = "d";
		BitStr A(s);
		int t = 1;
		for (uint i = 0; i < strlen(s); i++)
		{
			if (s[i] != A[i])t = 0;
		}
		EXPECT_EQ(t, 1);
	}
	TEST(Operator, Assign)
	{
		BitStr B;
		BitStr A("101010");
		EXPECT_EQ(A == B, false);
		B = A;
		EXPECT_EQ(A == B, true);
	}
	TEST(Operator, Add1)
	{
		BitStr A("101010");
		BitStr B("001101");
		BitStr C;
		BitStr R("100111");

		C = (A + B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, AddDiffSize1)
	{
		BitStr A("11001010");
		BitStr B("001101");
		BitStr C;
		BitStr R("11000111");

		C = (A + B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, AddDiffSize2)
	{
		BitStr B("11001010");
		BitStr A("001101");
		BitStr C;
		BitStr R("11000111");

		C = (A + B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, Mod_GF0_1)
	{
		BitStr A("1011010");
		BitStr B("101");
		BitStr C;
		BitStr R("0");

		C = (A % B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, Mod_GF0_2)
	{
		BitStr A("0");
		BitStr B("101");
		BitStr C;
		BitStr R("0");

		C = (A % B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, Mod_GF_2)
	{
		BitStr A("100");
		BitStr B("1011");
		BitStr C;
		BitStr R("100");

		C = (A % B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, Mod_GF_3)
	{
		BitStr A("1000");
		BitStr B("1011");
		BitStr C;
		BitStr R("11");

		C = (A % B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, Mod_GF_4)
	{
		BitStr A("10000");
		BitStr B("1011");
		BitStr C;
		BitStr R("110");

		C = (A % B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, Mod_GF_5)
	{
		BitStr A("100000");
		BitStr B("1011");
		BitStr C;
		BitStr R("111");

		C = (A % B);
		EXPECT_EQ(C == R, true);
	}
	TEST(Operator, Mod_GF_6)
	{
		BitStr A("1000000");
		BitStr B("1011");
		BitStr C;
		BitStr R("101");

		C = (A % B);
		EXPECT_EQ(C == R, true);
	}
	TEST(BitStr, AsNumber)
	{
		BitStr A("1000000");
		Number a((char*)"1000000");
		EXPECT_EQ(A.AsNumber()==a, true);
	}
