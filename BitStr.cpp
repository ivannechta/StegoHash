#include "BitStr.h"

int BitStr::align(char* s, uint len) //errase first zero series in number (0011 = 11 ), and return how much it was
{
	uint i = 0;
	while (s[i] != '1')
	{
		i++;
		if (i >= len)return i;
	}

	for (uint j = i; j <= len; j++)
	{
		s[j - i] = s[j];
	}
	return i;
}
void BitStr::Xor(char* res, BitStr b)
{
	for (uint i = 0; i < b.size; i++)
	{
		res[i] = (res[i] == b[i]) ? '0' : '1';
	}
}
BitStr::BitStr()
{
	bits = NULL;
	size = 0;
}

BitStr::BitStr(const char* s) 
{
	size = (uint)strlen(s);

	uint offset = 0;
	while ((s[offset] != '1') && (size > 1)) //errase first zero series in number (0011 = 11 )
	{
		size--;
		offset++;
	}
	bits = new char[size + 1];
	for (uint i = 0; i < size; i++)
	{
		bits[i] = s[i + offset];
	}
	bits[size] = 0;
	}
char BitStr::operator[](uint i)
{
	if ((i >= 0) && (i < size))
	{
		return bits[i];
	}
	return 0;
}

BitStr& BitStr::operator+(BitStr & b)
{
	uint Min, Max;
	Max = max(size, b.GetSize());
	Min = min(size, b.GetSize());
	char* tmp = new char[Max + 1];

	for (uint i = 0; i < Min; i++)
	{
		tmp[Max - i - 1] = (bits[size - i - 1] == b[b.GetSize() - i - 1]) ? '0' : '1';
	}
	tmp[Max] = 0;
	if (size > b.GetSize())
	{
		for (uint i = 0; i < Max - Min; i++)
		{
			tmp[i] = bits[i];
		}
	}
	else
	{
		for (uint i = 0; i < Max - Min; i++)
		{
			tmp[i] = b[i];
		}
	}
	BitStr* t = new BitStr(tmp);
	return *t;
	}

BitStr BitStr::operator=(BitStr & b)
{
	if (this == &b) return *this;

	uint sizet = b.GetSize();
	delete bits;
	bits = new char[sizet + 1];
	for (uint i = 0; i < sizet; i++)
	{
		bits[i] = b[i];
	}
	bits[sizet] = 0;
	size = sizet;

	return *this;
}
bool BitStr::operator==(BitStr & b)
{
	if (size != b.GetSize()) return false;
	for (uint i = 0; i < size; i++)
	{
		if (bits[i] != b[i]) return false;
	}
	return true;
}
bool BitStr::operator!=(BitStr & b)
{
	return !((*this) == b);
}
Number BitStr::AsNumber ()
{
	char* c = new char[size + 1]; c[size] = 0;
	for (int i = 0; i < size; i++) {
		c[i] = bits[i];
	}
	return Number(c);
}

BitStr& BitStr::operator%(BitStr & b)
{
	char* ost = new char[size + 1];
	uint snosim = 0;
	uint t = 0;

	while (snosim < size)
	{
		ost[t++] = bits[snosim++]; ost[t] = 0;

		if (t == b.GetSize())
		{
			Xor(ost, b);
			t = t - align(ost, b.GetSize());
		}
	}
	BitStr* Ost = new BitStr(ost);
	return *Ost;
}

uint BitStr::GetSize()
{
	return size;
}
char* BitStr::GetFormatedString(uint m)
{
	char* res = new char[m + 1];
	res[m] = 0;
	for (uint i = 0; i < m - size; i++)
	{
		res[i] = '0';
	}
	for (int i = 0; i < size; i++)
	{
		res[m - size + i] = bits[i];
	}
	return res;
}

void BitStr::Show()
{
	printf("%s", bits);
}