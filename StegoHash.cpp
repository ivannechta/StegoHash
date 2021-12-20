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
		StegoContainer* s = new StegoContainer("101");
		printf("Write(00) ->%s\n", s->WriteToContainer("00"));
		printf("Write(01) ->%s\n", s->WriteToContainer("01"));
		printf("Write(10) ->%s\n", s->WriteToContainer("10"));
		printf("Write(11) ->%s\n", s->WriteToContainer("11"));

		printf("Read(111) ->%s\n", s->ReadFromContainer("111"));
		printf("Read(001) ->%s\n", s->ReadFromContainer("001"));
		printf("Read(101) ->%s\n", s->ReadFromContainer("101"));
		printf("Read(100) ->%s\n", s->ReadFromContainer("100"));
	}
	catch (int i)
	{
		printf("Error Code=%d\n", i);
	}
#endif	
}
