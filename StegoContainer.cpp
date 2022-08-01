#include "StegoContainer.h"

uint Primes[] = { 1,3,7,13,19,37,67,131,283 };

StegoContainer::StegoContainer(const char* em)
{
	Len = strlen(em);
	Capacity = (uint)trunc(log(Len + 1) / log(2)); 
	if (Capacity >= 9)throw 2; //Very big prime	
	L = new Lambda(Capacity, Primes[Capacity]);
	EmptyMessage = new char[Len + 1];
	strcpy_s(EmptyMessage, Len + 1, em);
	Info();
}

uint StegoContainer::GetContainerCapacity()
{
	return Capacity;
}

char* StegoContainer::ReadFromContainer(const char* st_cont)
{	
	BitStr* d = new BitStr(st_cont);
	BitStr *s=L->FLambda(d);
	return s->GetFormatedString(Capacity);
}

char* StegoContainer::WriteToContainer(const char* sm)
{
	if (strlen(sm) != Capacity) throw 3;
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