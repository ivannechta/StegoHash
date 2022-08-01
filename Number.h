#pragma once
#include <string.h>
#include <stdio.h>

class Number {
private:
	char* digit;
	int size;
public:
	inline int GetSize()
	{
		return size;
	}
//#pragma region Region_1
//#pragma endregion Region_1
	Number() {
		size = 0; digit = NULL;
	}

	Number(char* c,int s=-1) {
		if (c == NULL) throw 0;		
		size = (s==-1)?strlen(c):s;
		if (size==0) throw 0;
		digit = new char[size + 1];
		strcpy(c, digit, size + 1 );
		for (int i = 0; i < size; i++)
		{
			digit[i] -= '0';
		}
	}
	Number& operator=(Number b) {
		if (size != 0)delete digit;
		size = b.GetSize();
		
		digit = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			digit[i] = b[i];
		}
		digit[size] = 0;
		return (*this);
	}

	Number operator *(int newsize) { //add some 0 to the end: x=11; x*5 ->00011      
		if (newsize <= size) return *this;
		char* c = new char[newsize + 1];		
		for (int i = 0; i < newsize-size; i++) {
			c[i] = 0;
		}	
		strcpy(digit, &c[newsize-size], size);
		c[newsize] = 0;
		delete digit;
		digit = new char[newsize + 1];
		size=newsize;
		strcpy(c, digit, size + 1);
		return *this;
	}

	bool operator<(Number B) {
		Number a;		
		Number b; 
		a = *this;
		b = B;
		int max = (a.GetSize() < b.GetSize()) ? b.GetSize() : a.GetSize();
		a* max;
		b* max;
		for (int i = 0; i < max; i++) {
			if (a[i] < b[i])return true;
			if (a[i] > b[i])return false;
		}		
		return false;
	}

	Number operator +(Number b) { //Xor		
		if (this->size != b.GetSize()) throw 1;
		char* c = new char[size + 1]; 
		c[size] = 0;
		for (int i = 0; i < size; i++){
			c[i] = (digit[i] ^ b[i])+'0';
		}
		return Number(c,size);
	}

	Number operator -() { //compact: 00011 ->11		
		int offset = 0;
		while ((digit[offset] == 0) && (offset < size - 1)) {
			offset++;
		}	
		size -= offset;
		for (int i = 0; i < size; i++) {
			digit[i] = digit[i + offset];
		}
		digit[size] = 0;
		return *this;
	}

	Number operator <<(int b) {
		char* c = new char[size + 2];
		strcpy(digit,c, size + 1);
		c[size] = b ;
		c[size + 1] = 0;

		delete digit;
		digit=new char[size + 2];
		size++;		
		strcpy(c,digit, size + 1);
		
		return *this;
	}

	Number operator >>(int b) { // 0011>>5 -> 11 ->11000, where b is num size
		char* c = new char[b + 2];
		bool errorFlag = true;
		int k = 0;
		while (k < b) {
			if (digit[k] == 1) { errorFlag = false; break; }
			k++;
		}
		if (k == b) throw 4; //num has 0 only

		for (int i = 0; i < b; i++) {
			c[i] = (i+k<size) ? digit[i+k]+'0': '0';
		}
		c[b] = 0;
		return (Number(c));
	}


	int operator [](int i) { // Numeration from hiest digit (as in String): "01" -> Num[0]=0; 
		if (size > i) return digit[i];
		return -1;
	}

	bool operator ==(Number b) {
		if (size != b.GetSize())return false;
		for (int i = 0; i < size; i++)
		{
			if (this->digit[i] != b[i])return false;
		}
		return true;
	}

	bool operator !=(Number b) {
		if (size != b.GetSize())return true;
		for (int i = 0; i < size; i++)
		{
			if (this->digit[i] != b[i])return true;
		}
		return false;
	}

	void V() {
		for (int i = 0; i < size; i++)
		{
			printf("%d",(unsigned int)digit[i]);
		}
		printf("\n");	
	}
	void strcpy(char* s, char* d, int n)
	{
		for (int i = 0; i < n; i++)
		{
			d[i] = s[i];
		}
	}
};

