#include <iostream>
#include "BitStr.h"
#include <string.h>
#include "LambdaTable.h"
//#include "gtest/gtest.h"



int main(int argc,char *argv[])
{	
	Lambda* L = new Lambda(2, 7);
	L->Show();
	/*testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();	
	*/
}
