#pragma once
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "BitStr.h"
#include "DiscrLog.h"


typedef unsigned int uint;

class Lambda 
{
private:
	uint M, N;	
	uint* L; //stores position of one bit.
	BitStr** code;
	BitStr* PrimePolynom;
	DiscrLog *D;
public:
	char*	Dec2Bin			(uint x);
	void	InitCode();

public:
	Lambda(uint m, uint prime);
	void	Show();
	//[[deprecated ("Try to change GetDByCode_uint")]]
	//uint	GetDByCode_uint	(BitStr* a);

	
	[[deprecated("Try to change GetDByCode")]]
	BitStr	GetDByCode		(BitStr* a);	
	[[deprecated("Try to change FLambda")]]
	BitStr* FLambda(BitStr *b);
};