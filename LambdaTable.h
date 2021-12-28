#pragma once
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "BitStr.h"

typedef unsigned int uint;

class Lambda 
{
private:
	uint M, N;	
	uint* L; //stores position of one bit.
	BitStr** code;
	BitStr* PrimePolynom;
public:
	char*	Dec2Bin			(uint x);
	void	InitCode();

public:
	Lambda(uint m, uint prime);
	void	Show();
	uint	GetDByCode_uint	(BitStr* a);
	BitStr	GetDByCode		(BitStr* a);	
	BitStr* FLambda(BitStr *b);
};