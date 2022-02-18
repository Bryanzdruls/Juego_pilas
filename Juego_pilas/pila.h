#pragma once
#include "Nodo.h"

class pila_lista
{
private:
	//Atributos.
	Nodo* punta;
	int limite, tope;

	//Metodos.
public:
	pila_lista(int);//Constructor.
	void apilar(int);//Set.
	int desapilar(); //Get.

	bool pilaVacia();
	bool pilaLlena();
	void llenarPila(pila_lista*);//Pasar datos, de pila llena a pila vacia.
	void invertirPila();
	void mostrarPila();
	int getLimite();
	bool pilaCorrecta(pila_lista*);

	void pilaJuego();
	void llenarPila1();
	void llenarPila2();

	void insertarInicio(int);
};

