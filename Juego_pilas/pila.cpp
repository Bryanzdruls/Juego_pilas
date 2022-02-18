#include "pila.h"
#include<iostream>
#include"Nodo.h"

using namespace std;
pila_lista::pila_lista(int tam)
{
	limite = tam;
	tope = 0;
	punta = nullptr;
};

void pila_lista::apilar(int d)//Similar al Set.
{
	tope++;
	insertarInicio(d);
}

int pila_lista::desapilar()//Similar al Get.
{
	Nodo* p = punta;
	int r = p->getDato();
	punta = punta->getliga();
	tope--;
	delete(p);
	return r;
}

bool pila_lista::pilaVacia()//Validacion vacia.
{
	bool r = false;
	if (tope == 0)
	{
		r = true;
	}
	return r;
}

bool pila_lista::pilaLlena()//Validacion llena(true = llena).
{
	if (tope == limite)
		return true;
	else
		return false;
}

void pila_lista::llenarPila(pila_lista* a)
{
	while (a->pilaVacia() == false)
	{
		apilar(a->desapilar());
	}
}

void pila_lista::insertarInicio(int d)
{
	Nodo* x = new Nodo();

	x->setDato(d);

	if (punta == nullptr)
	{
		punta = x;
	}
	else
	{
		x->setLiga(punta);
		punta = x;
	}
}

void pila_lista::mostrarPila()
{
	pila_lista* aux = new pila_lista(limite);
	int r = 0;
	while (pilaVacia() == false)
	{
		r = desapilar(); //Se vacia la pila principal.
		cout << "|" << r << "|" << endl;
		aux->apilar(r);
	}
	llenarPila(aux); //Se llena la pila auxiliar.
}

void pila_lista::invertirPila()
{
	pila_lista* aux1 = new pila_lista(limite);
	pila_lista* aux2 = new pila_lista(limite);
	int r = 0;

	while (!pilaVacia())
	{
		r = desapilar();
		aux1->apilar(r);
	}
	aux2->llenarPila(aux1);
	llenarPila(aux2);
}
int pila_lista::getLimite()
{
	return limite;
}

bool pila_lista::pilaCorrecta(pila_lista* p)
{
	if (!pilaVacia() && p->tope == 4)
	{
		pila_lista* aux = new pila_lista(4);
		int  dato = 0;
		const int validar = desapilar();
		bool correcto = true;
		apilar(validar);
		do
		{
			dato = desapilar();
			aux->apilar(dato);
			if (dato != validar)
			{
				correcto = false;
			}
		} while (!aux->pilaLlena() && !pilaVacia());
		llenarPila(aux);
		invertirPila();
		return correcto;
	}
	else
	{
		return false;
	}
}
void pila_lista::llenarPila1()
{
	while (!pilaLlena())
	{
		apilar(1);
		apilar(2);
	}
}

void pila_lista::llenarPila2()
{
	while (!pilaLlena())
	{
		apilar(2);
		apilar(1);
	}
}
void pila_lista::pilaJuego()
{
	pila_lista* p1 = new pila_lista(4);
	pila_lista* p2 = new pila_lista(4);
	pila_lista* p3 = new pila_lista(4);
	
	p1->llenarPila1();
	p2->llenarPila2();
	cout << "p1" << endl;
	p1->mostrarPila();
	cout << endl << endl;
	cout << "p2" << endl;
	p2->mostrarPila();
	cout<< endl;
	do
	{
		if (!p1->pilaVacia() && p3->pilaVacia())
		{
			p3->apilar(p1->desapilar());
		}
		else
		{
			if ((!p1->pilaVacia() && !p3->pilaLlena()) && (p3->pilaVacia()) || (p3->punta->getDato() == 2 && p1->punta->getDato()== 2))
				p3->apilar(p1->desapilar());
			else
			{
				if (!p2->pilaVacia() && (p3->pilaVacia()) || (p3->punta->getDato() == 2 && p2->punta->getDato() == 2))
					p3->apilar(p2->desapilar());
				else
				{
					if ((!p1->pilaVacia() && !p2->pilaLlena()) && (p1->punta->getDato() == 1 && p2->punta->getDato() == 1))
					{
						p2->apilar(p1->desapilar());
						
					}
					else
					{
						if ((!p2->pilaVacia() && !p1->pilaLlena()) && (p1->punta->getDato() == 1 && p2->punta->getDato() == 1))
						{
							
							if ((p2->pilaLlena() && p1->tope == 1)&& (p1->punta->getDato() == 1 && p2->punta->getDato() == 1))
							{
								p1->apilar(p2->desapilar());
								p1->apilar(p2->desapilar());
								p1->apilar(p2->desapilar());
								
								p3->apilar(p2->desapilar());

							}
							else
							{
								p1->apilar(p2->desapilar());
							}
						}
					}
				}
			}	
		}
		cout << "p1" << endl;
		p1->mostrarPila();
		cout << endl << endl;
		cout << "p2" << endl;
		p2->mostrarPila();
		cout << endl << endl;
		cout << "p3" << endl;
		p3->mostrarPila();
		cout << endl << endl;
		cout << "Presione cualquier tecla para continuar."<< endl;
		cin.get();
	} while (!p1->pilaCorrecta(p1));
	
}

