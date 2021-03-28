
#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include<string.h>
#include<string>

using namespace std;

class Lista
{
private:
	Nodo* primero;
	Nodo* ultimo;
public:
	Lista();

	bool estaVacia();
	void agregar(int, string);
	void imprimir(string);
	void sumar(Lista, Lista, int, string);
	void restar(Lista, Lista, int, string);
	void multiplicar(Lista, Lista, int, int, string);
	int determinante(Lista, int, int);
	bool isIrregular(Lista, int, int);
};
#endif

