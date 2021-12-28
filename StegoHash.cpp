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
		printf("Write(000) ->%s\n", s->WriteToContainer("0000"));
		printf("Write(001) ->%s\n", s->WriteToContainer("0001"));
		printf("Write(010) ->%s\n", s->WriteToContainer("0010"));
		printf("Write(011) ->%s\n", s->WriteToContainer("0011"));
		printf("Write(100) ->%s\n", s->WriteToContainer("0100"));
		printf("Write(101) ->%s\n", s->WriteToContainer("0101"));
		printf("Write(110) ->%s\n", s->WriteToContainer("0110"));
		printf("Write(111) ->%s\n", s->WriteToContainer("0111"));
		printf("Write(000) ->%s\n", s->WriteToContainer("1000"));
		printf("Write(001) ->%s\n", s->WriteToContainer("1001"));
		printf("Write(010) ->%s\n", s->WriteToContainer("1010"));
		printf("Write(011) ->%s\n", s->WriteToContainer("1011"));
		printf("Write(100) ->%s\n", s->WriteToContainer("1100"));
		printf("Write(101) ->%s\n", s->WriteToContainer("1101"));
		printf("Write(110) ->%s\n", s->WriteToContainer("1110"));
		printf("Write(111) ->%s\n", s->WriteToContainer("1111"));
	}
	catch (int i)
	{
		printf("Error Code=%d\n", i);
	}
#endif	
}
