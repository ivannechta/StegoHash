#pragma once
#include "Number.h"
class DiscrLog {
private:
	Number A;
	Number P,Y;	
	int Power;
public:
	DiscrLog(Number p,Number y) {		
		A = Number((char*)"1");
		P = p;
		Y = y;
		-Y;
		Power = -1;	
	}

	int Snosim() {
		int i = 0;
		while (A.GetSize() < P.GetSize()) {
			A << 0; i++;
		}
		return i;
	}

	void Divide() {
		if (Y.GetSize() > P.GetSize())throw 7;
		-Y;
		if (Y == Number((char*)"0")) {
			return;
		}
		Power++;

		while (A != Y) {
			if (A.GetSize()<P.GetSize()){ 
				A << 0; Power++;
			}
			else {				
				A = (A + P);				
				-A;				
			}
		}
	}

	inline int GetPower() {
		return Power;
	}

};
