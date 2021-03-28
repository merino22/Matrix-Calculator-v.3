#pragma once
#ifndef MATRIZ_H
#define MATRIZ_H

#include<fstream>
#include<string.h>
#include "Lista.h"

using namespace std;

class Matriz
{
private:
	string path;

public:
	//Constructores
	Matriz(void);
	Matriz(string);

	//Creacion de matriz de archivo a lista enlazada doble
	Lista createMatrix(void);

	//Filas y columnas de la Matriz creada
	int getFilas(void);
	int getColumnas(void);

	void setPath(string);
	string getPath(void);

	//Funciones de Operaciones Matriciales
	void sumar(Matriz, Matriz);
	void restar(Matriz, Matriz);
	void multiplicar(Matriz, Matriz);
	int determinante(Matriz, int, int);
};
#endif

