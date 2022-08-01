#include "LambdaTable.h"

char* Lambda::Dec2Bin(uint x)
{
	uint n = (x > 0) ? (uint)floor(log(x) / log(2)) : 0;
	char* a;
	a = new char[n + 2];
	uint i = 0; a[n + 1] = 0;
	do
	{
		a[n - i] = (x % 2) ? '1' : '0';
		x = x / 2;
		i++;
	} while (x > 0);
	return a;
}

void Lambda::InitCode()
{	
	char* tmp = new char[N + 1];
	BitStr* t; uint j;
	code[0] = new BitStr("0");
	tmp[0] = '1';
	for (uint i = 1; i < N; i++)
	{
		for (j = 1; j < i; j++)
		{
			tmp[j] = '0';
		}
		tmp[j] = 0;

		t = new BitStr;
		*t = (*new BitStr(tmp)) % *PrimePolynom;
		code[i] = t;
	}
}

Lambda::Lambda(uint m, uint prime)
{
	if (m > 10) throw 1; //Very big Lambda-table
	if ((prime >> (m + 1)) > 0)throw 2; //very big prime ?????????
	M = m;
	N = (1 << M);
	L = new uint[N];
	code = new BitStr * [N];
	for (uint i = 0; i < N; i++)
	{
		L[i] = i;
	}
	PrimePolynom = new BitStr(Dec2Bin(prime));
	InitCode();
}

void Lambda::Show()
{
	for (uint i = 0; i < N; i++)
	{
		printf("%d -> %s\n", L[i], code[i]->GetFormatedString(M));
	}
}

BitStr Lambda::GetDByCode(BitStr* a)
{
	uint i;	

	D = new DiscrLog(PrimePolynom->AsNumber(), a->AsNumber());
	D->Divide();
	i = D->GetPower()+1;



	char* tmp = new char[i + 1];
	tmp[0] = '1'; tmp[i] = 0;
	for (uint t = 1; t < i; t++)
	{
		tmp[t] = '0';
	}
	return BitStr(tmp);
}

BitStr* Lambda::FLambda(BitStr *b)
{
	BitStr* tmp = new BitStr();
	*tmp = (*b) % (*PrimePolynom);
	return tmp;
}
