#pragma once
#include <string.h>
#include <stdio.h>
#include "Number.h"

typedef unsigned int uint;
class BitStr 
{
private:
	char *bits;
	uint size;
	uint max	(uint a, uint b) { return (a > b) ? a : b; }
	uint min	(uint a, uint b) { return (a < b) ? a : b; }
	int	 align	(char* s, uint len); //errase first zero series in number (0011 = 11 ), and return how much it was
	void Xor	(char* res, BitStr b);
	
public:
	BitStr();
	BitStr(const char* s);	
	char	operator [] (uint i);	
	BitStr& operator +  (BitStr& b);
	BitStr	operator =  (BitStr& b);
	bool	operator == (BitStr& b);	
	bool	operator != (BitStr& b);	
	BitStr& operator %  (BitStr& b);
	Number	AsNumber();
	/* [[deprecated("Memory licage in operator(char*)")]]
			operator char*  ();	
	*/
	uint  GetSize();
	char* GetFormatedString(uint m);
	void  Show();
};
