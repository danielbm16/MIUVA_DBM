#include "pch.h"
#include "LCD.h"
#include <iostream>
using namespace std;

int main()
{
inicio:

	int eleccion;
    CLCD DISPLAY;

	fflush(stdin);
	system("cls");

	cout << "BONILLA MENDOZA LUIS DANIEL - 201946726";
	cout << "\nSIMONIN MARQUEZ ANA PATRICIA - 201921657";
	cout << "\nPAZARAN HERNANDEZ MIGUEL ANGEL - 201906548";
	cout << "\n\n";

	cout << "\t\t\tPRACTICAS PROGRAMACION ORIENTADA A OBJETOS\n\n" << endl;
	cout << "\t\tPractica 2 Constructores y Destructores\n\n";

	char Nombre[30];
	char Nombre2[30];
	char XD, XD2;

	cout << "\nSe reiniciara el display..." << endl;
	Sleep(1000);
	cout << "\n5..." << endl;
	Sleep(1000);
	cout << "\n4..." << endl;
	Sleep(1000);
	cout << "\n3..." << endl;
	Sleep(1000);
	cout << "\n2..." << endl;
	Sleep(1000);
	cout << "\n1..." << endl;
	Sleep(1000);

	DISPLAY.Reset();
	DISPLAY.Borrar();
	cout << "\n\nEl display se reinicio..." << endl;


	system("pause");
	system("cls");

	DISPLAY.Inicializar();

	cout << "BONILLA MENDOZA LUIS DANIEL - 201946726";
	cout << "\nSIMONIN MARQUEZ ANA PATRICIA - 201921657";
	cout << "\nPAZARAN HERNANDEZ MIGUEL ANGEL - 201906548";
	cout << "\n\n";

	cout << "\t\t\tPRACTICAS PROGRAMACION ORIENTADA A OBJETOS\n\n" << endl;
	cout << "\t\tPractica 2 Constructores y Destructores\n\n";

	cout << "\n\nIngresa tu nombre en la primera fila, usa espacio como _, el maximo de carateres es de 16:\n";
	cin >> Nombre;

	cout << "\n\nSu nombre tiene: ";
	auto largo = string(Nombre).size();
	cout << largo;
	cout << " letras\n";

	cout << "\nSu primera palabra se muestra en la primera fila del LCD..." << endl << endl;

	cin.ignore();
	for (int i = 0; i < largo; i++)
	{
		XD = Nombre[i];
		DISPLAY.Escribir(XD);
		Sleep(10);
	}

	DISPLAY.Linea2LCD();
	cout << "\n\nIngrese la segunda palabra: " << endl;
	cin >> Nombre2;

	cout << "\n\nSu nombre tiene: ";
	auto largo2 = string(Nombre2).size();
	cout << largo2;

	cout << " letras\n";

	cout << "\n\nSu segunda palabra se muestra en la segunda fila del LCD..." << endl << endl;

	cin.ignore();
	for (int i = 0; i < largo2; i++)
	{
		XD2 = Nombre2[i];
		DISPLAY.Escribir(XD2);
		Sleep(10);
	}
	cout << "\n\nSe borrara el contenido en el LCD...\n\n";
	system("pause");
	DISPLAY.~CLCD();

	cout << "\n\nDeseas volver a comenzar? SI = 1, NO = 0 : ";
	cin >> eleccion;

	if (eleccion == 1)
	{
		goto inicio;
	}
	else
	{
		fflush(stdin);
		system("cls");

		cout << "GRACIAS POR VER <3" << endl << endl;
		system("pause");
	}
    return 0;

}