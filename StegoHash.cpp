#include <iostream>
#include "BitStr.h"
#include <string.h>
#include "LambdaTable.h"
//#include "gtest/gtest.h"



int main(int argc,char *argv[])
{		
	try {
		Lambda* L = new Lambda(5, 61);
		L->Show();
	}
	catch (int i) 
	{
		printf("Error Code=%d\n",i);
	
	}
	
	/*testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();	
	*/
}
