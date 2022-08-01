#include <iostream>
#include "BitStr.h"
#include <string.h>
#include "LambdaTable.h"
#include "StegoContainer.h"
//#define UnitTEST

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
		
		StegoContainer *s=new StegoContainer("1010101");
		printf("Capacity=%d \n", s->GetContainerCapacity());

		printf("Write(000) ->%s\n", s->WriteToContainer("000"));
		printf("Write(001) ->%s\n", s->WriteToContainer("001"));
		printf("Write(010) ->%s\n", s->WriteToContainer("010"));
		printf("Write(011) ->%s\n", s->WriteToContainer("011"));
		printf("Write(100) ->%s\n", s->WriteToContainer("100"));
		printf("Write(101) ->%s\n", s->WriteToContainer("101"));
		printf("Write(110) ->%s\n", s->WriteToContainer("110"));
		printf("Write(111) ->%s\n", s->WriteToContainer("111"));

	}
	catch (int i)
	{
		printf("Error Code=%d\n", i);
	}
#endif	
}
