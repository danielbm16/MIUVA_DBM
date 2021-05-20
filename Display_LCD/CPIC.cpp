#include "pch.h"
#include <iostream>
using namespace std;

void CPIC::enviardato(int control, int dato)
{
	escribirusb[0] = control;

		//PRACTICA 2 DISPLAY

		if (control == 3)
		{
			escribirusb[0] = 3;
			escribirusb[1] = dato;
			MiUsb.SendPacket(escribirusb, 5);
		}
}