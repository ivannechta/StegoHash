#pragma once
#include <string.h>
#include <stdio.h>
#include "LambdaTable.h"

typedef unsigned int uint;

extern uint Primes[];

class StegoContainer
{
private:
	char *EmptyMessage;
	uint Len;
	Lambda *L;
	uint Capacity;

public:

			StegoContainer		(const char* em);
	uint	GetContainerCapacity();
	char*	ReadFromContainer	(const char* st_cont);
	char*	WriteToContainer	(const char* sm);
	void Info();
};