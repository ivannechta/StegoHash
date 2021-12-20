#pragma once
#include <string.h>
#include <stdio.h>
#include "LambdaTable.h"

typedef unsigned int uint;

#ifndef PRIME
#define PRIME

#endif //  PRIME

class StegoContainer
{
private:

	char *EmptyMessage;
	uint Len;
	Lambda *L;
	uint Capacity;
	uint Primes(uint i)
	{
		uint tmp[] = { 1,3,7,13,17,37,67,131,257,521,1031,2053};
		return tmp[i];
	}

public:

	StegoContainer(const char * em)
	{
		Len = strlen(em);
		Capacity = GetContainerCapacity(Len);
		L = new Lambda(Capacity, Primes(Capacity));
		EmptyMessage = new char[Len+1];	
		strcpy_s(EmptyMessage,Len+1,em);
		Info();
	}

	uint GetContainerCapacity(uint N)
	{
		return (uint)trunc(log(N+1)/log(2));
	}

	char* ReadFromContainer(const char* st_cont)
	{		
		BitStr s("0");

		for (int i = Len - 1; i >= 0; i--)
		{
			if (st_cont[Len - i - 1] == '1')
			{				
				//int tmp = (1 << i) - 1;
				BitStr *d = L->GetCodeByD(i + 1);				
				s = s + *d;
			}			
		}		
		return s.GetFormatedString(Capacity);
	}

	char *WriteToContainer(const char* sm) 
	{
		BitStr s = BitStr(sm);
		BitStr em=BitStr(EmptyMessage);
		BitStr prime = BitStr(L->Dec2Bin(Primes(Capacity)));
		BitStr u = em % prime;
		BitStr v = u + s;
		//printf("%s %% %s = %s\n", (char*)em, (char*)prime,(char*)u);
		//printf("v=%s\n", (char*)v);
		BitStr d = L->GetDByCode(&v);
		//printf("d=%s\n", (char*)d);
		BitStr w = em + d;
		//printf("w=%s\n", (char*)w);
		return w.GetFormatedString(Len);
	}

	void Info()
	{
		L->Show();
	}
};