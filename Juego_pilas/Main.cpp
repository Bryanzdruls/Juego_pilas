#include<iostream>
#include"pila.h"
using namespace std;

void menuPilas();

int main()
{
		
	int opt = 0;
	pila_lista* p1 = new pila_lista(4);
	pila_lista* p2 = new pila_lista(4);
	pila_lista* p3 = new pila_lista(4);
	do
	{
		menuPilas();
		cin >> opt;
		switch (opt)
		{
		case 1://jugar
			p1->pilaJuego();
			cout << "Juego Terminado." << endl;
			break;
		case 2://salir
			cout << "Gracias por utilizar mi programa." << endl;
			break;
		default:
			cout << "opcion incorrecta." << endl;
			break;
		}

	} while (opt !=2);
	return 0;
};

void menuPilas()
{

	cout << "1. Iniciar." << endl;
	cout << "2. Salir." << endl;


	cout << "Escoga una opcion." << endl;
}