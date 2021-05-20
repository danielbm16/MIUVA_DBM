#pragma once
#include "CPIC.h"

class CLCD
{
private:
	CPIC MiLCD;

public:
	CLCD();
	~CLCD();
	void Inicializar();
	void Borrar();
	void Reset();
	void Escribir(char);
	void Linea2LCD();
};
