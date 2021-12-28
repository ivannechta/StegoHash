#include <iostream>
#include "BitStr.h"
#include <string.h>
#include "LambdaTable.h"
#include "StegoContainer.h"
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
		
		StegoContainer* s = new StegoContainer("111111111111111");
		printf("Write(1000) ->%s\n", s->WriteToContainer("1000"));	
	}
	catch (int i)
	{
		printf("Error Code=%d\n", i);
	}
#endif	
}
