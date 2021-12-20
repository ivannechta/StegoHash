#include "StegoContainer.h"

uint Primes[] = { 1,3,7,13,17,37,67,131,257,521,1031,2053 };

StegoContainer::StegoContainer(const char* em)
{
	Len = strlen(em);
	Capacity = GetContainerCapacity(Len);
	L = new Lambda(Capacity, Primes[Capacity]);
	EmptyMessage = new char[Len + 1];
	strcpy_s(EmptyMessage, Len + 1, em);
	Info();
}

uint StegoContainer::GetContainerCapacity(uint N)
{
	return (uint)trunc(log(N + 1) / log(2));
}

char* StegoContainer::ReadFromContainer(const char* st_cont)
{
	BitStr s("0");

	for (int i = Len - 1; i >= 0; i--)
	{
		if (st_cont[Len - i - 1] == '1')
		{
			BitStr* d = L->GetCodeByD(i + 1);
			s = s + *d;
		}
	}
	return s.GetFormatedString(Capacity);
}

char* StegoContainer::WriteToContainer(const char* sm)
{
	BitStr s = BitStr(sm);
	BitStr em = BitStr(EmptyMessage);
	BitStr prime = BitStr(L->Dec2Bin(Primes[Capacity]));
	BitStr u = em % prime;
	BitStr v = u + s;
	BitStr d = L->GetDByCode(&v);
	BitStr w = em + d;
	return w.GetFormatedString(Len);
}

void StegoContainer::Info()
{
	L->Show();
}