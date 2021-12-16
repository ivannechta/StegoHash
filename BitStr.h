#pragma once
#include <string.h>
#include <stdio.h>

typedef unsigned int uint;
class BitStr 
{
private:
	char *bits;
	uint size;

public:
	BitStr(const char* s) {
		size = strlen(s);
		bits = new char[size+1];
		for (int i = 0; i < size;i++) 
		{
			bits[i] = s[i];		
		}
		bits[size] = 0;	
	}
	char operator[](int i)
	{
		if ((i >= 0) && (i < size))
		{
			return bits[i];
		}
		return 0;
	}

	void Show()
	{
		printf("%s",bits);	
	}
};
