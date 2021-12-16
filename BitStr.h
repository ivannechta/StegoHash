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
	BitStr()
	{
		bits = NULL;
		size = 0;	
	}

	BitStr(const char* s) {
		size = (uint)strlen(s);
		bits = new char[size+1];
		for (uint i = 0; i < size;i++) 
		{
			bits[i] = s[i];		
		}
		bits[size] = 0;	
	}
	char operator[](uint i)
	{
		if ((i >= 0) && (i < size))
		{
			return bits[i];
		}
		return 0;
	}

	BitStr operator+(BitStr&b)
	{ 
		uint sizet = (uint)(size < b.GetSize() ? size : b.GetSize());
		char* tmp = new char[sizet+1];
		
		for (uint i = 0; i < sizet; i++)
		{
			tmp[i] = (bits[i] == b[i]) ? '0' : '1';
		}
		tmp[sizet] = 0;

		return BitStr(tmp);
	}
	BitStr operator=(BitStr &b)
	{
		if (this == &b) return *this;

		uint sizet = b.GetSize();
		delete bits;
		bits = new char[sizet+1];
		for (uint i = 0; i < sizet; i++)
		{
			bits[i] = b[i];
		}
		bits[sizet] = 0;
		size = sizet;

		return *this;
	}
	bool operator==(BitStr& b)
	{
		if (size != b.GetSize()) return false;
		for (uint i = 0; i < size; i++)
		{
			if (bits[i] != b[i]) return false;
		}	
		return true;
	}
	bool operator!=(BitStr& b)
	{		
		return !((*this)==b);
	}


	uint GetSize() 
	{
		return size;
	}

	void Show()
	{
		printf("%s",bits);	
	}
};
