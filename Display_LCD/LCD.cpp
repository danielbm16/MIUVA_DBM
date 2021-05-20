#pragma once
#include "pch.h"

CLCD::CLCD()
{
	MiLCD.enviardato(3, 2);
	Sleep(10);
	MiLCD.enviardato(3, 18);
	Sleep(10);
	MiLCD.enviardato(3, 2);
	Sleep(10);
	MiLCD.enviardato(3, 18);
	Sleep(10);
	MiLCD.enviardato(3, 2);
	Sleep(10);
	MiLCD.enviardato(3, 10);
	Sleep(10);
	MiLCD.enviardato(3, 26);
	Sleep(10);
	MiLCD.enviardato(3, 10);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 14);
	Sleep(10);
	MiLCD.enviardato(3, 30);
	Sleep(10);
	MiLCD.enviardato(3, 14);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 6);
	Sleep(10);
	MiLCD.enviardato(3, 22);
	Sleep(10);
	MiLCD.enviardato(3, 6);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 17);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
}

CLCD::~CLCD()
{
	Borrar();
	Reset();
};

void CLCD::Inicializar()
{
	MiLCD.enviardato(3, 2);
	Sleep(10);
	MiLCD.enviardato(3, 18);
	Sleep(10);
	MiLCD.enviardato(3, 2);
	Sleep(10);
	MiLCD.enviardato(3, 18);
	Sleep(10);
	MiLCD.enviardato(3, 2);
	Sleep(10);
	MiLCD.enviardato(3, 10);
	Sleep(10);
	MiLCD.enviardato(3, 26);
	Sleep(10);
	MiLCD.enviardato(3, 10);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 14);
	Sleep(10);
	MiLCD.enviardato(3, 30);
	Sleep(10);
	MiLCD.enviardato(3, 14);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 6);
	Sleep(10);
	MiLCD.enviardato(3, 22);
	Sleep(10);
	MiLCD.enviardato(3, 6);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 17);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
};

void CLCD::Borrar()
{
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 1);
	Sleep(10);
	MiLCD.enviardato(3, 17);
	Sleep(10);
	MiLCD.enviardato(3, 1);
	Sleep(10);
}

void CLCD::Reset()
{
	MiLCD.enviardato(3, 3);
	Sleep(10);
	MiLCD.enviardato(3, 19);
	Sleep(10);
	MiLCD.enviardato(3, 3);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 1);
	Sleep(10);
	MiLCD.enviardato(3, 17);
	Sleep(10);
	MiLCD.enviardato(3, 1);
	Sleep(10);
}

void CLCD::Escribir(char digito)
{
	char datoLCD, resultado;

	cout << digito;
	resultado = digito & 240;
	datoLCD = (resultado >> 4) + 32;
	MiLCD.enviardato(3, datoLCD);
	Sleep(10);
	datoLCD = (resultado >> 4) + 32 + 16;
	MiLCD.enviardato(3, datoLCD);
	Sleep(10);
	datoLCD = (resultado >> 4) + 32;
	MiLCD.enviardato(3, datoLCD);
	Sleep(10);
	resultado = digito & 15;
	datoLCD = resultado + 32;
	MiLCD.enviardato(3, datoLCD);
	Sleep(10);
	datoLCD = resultado + 32 + 16;
	MiLCD.enviardato(3, datoLCD);
	Sleep(10);
	datoLCD = resultado + 32;
	MiLCD.enviardato(3, datoLCD);
	Sleep(10);
}

void CLCD::Linea2LCD()
{
	MiLCD.enviardato(3, 12);
	Sleep(10);
	MiLCD.enviardato(3, 28);
	Sleep(10);
	MiLCD.enviardato(3, 12);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
	MiLCD.enviardato(3, 16);
	Sleep(10);
	MiLCD.enviardato(3, 0);
	Sleep(10);
}

