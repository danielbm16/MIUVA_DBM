#pragma once
#include "CUsb.h"
#include <iostream>
using namespace std;

class CPIC : public CUsb
{
private:
	CUsb MiUsb;
	int datoPIC;
	BYTE escribirusb[5];
	BYTE leerusb[5];

public:
	void enviardato(int, int);
};