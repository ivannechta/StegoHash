#include <iostream>
#include "BitStr.h"
#include <string.h>
#include "LambdaTable.h"
#define UnitTEST

#ifdef UnitTEST
#include "gtest/gtest.h"
#endif // Test

int main(int argc,char *argv[])
{		

#ifdef UnitTEST
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

#else // UnitTEST
	try {
		Lambda* L = new Lambda(5, 61);
		L->Show();			
	}
	catch (int i)
	{
		printf("Error Code=%d\n", i);
	}
#endif	
}
