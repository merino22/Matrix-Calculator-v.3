#include "Nodo.h"
#include "Lista.h"
#include "Matriz.h"
#include<iostream>
#include<fstream>;
#include<string.h>
#include<string>

using std::cout;

int x, y, z;
Nodo* actualInferior;
Nodo* columnSetter;
bool check;

Lista::Lista() :primero(nullptr), ultimo(nullptr)
{
	x = 0;
	y = 0;
	z = 0;
	actualInferior = nullptr;
	columnSetter = nullptr;
	check = false;
}

bool Lista::estaVacia(void)
{
	return primero == nullptr;
}

void Lista::agregar(int _valor, string path)
{
	Nodo* nuevo = new Nodo(_valor, nullptr, nullptr);
	Matriz obj(path);
	int columnas = obj.getColumnas();
	int filas = obj.getFilas();

	if (estaVacia())
	{
		primero = nuevo;
		ultimo = nuevo;
		actualInferior = primero;
		columnSetter = primero;
	}
	else
	{
		Nodo* actual = ultimo;

		if (check == false)
		{
			if (x < columnas - 1)
			{
				ultimo->setSiguiente(nuevo);
				ultimo = nuevo;
				x++;
			}
			else
			{
				actualInferior->setInferior(nuevo);
				columnSetter = actualInferior->getSiguiente();
				actualInferior = actualInferior->getInferior();
				ultimo = actualInferior;
				check = true;
			}
		}
		else
		{
			if (columnSetter != nullptr)
			{
				columnSetter->setInferior(nuevo);
				columnSetter = columnSetter->getSiguiente();
				ultimo->setSiguiente(nuevo);
				ultimo = nuevo;
			}
			else
			{
				actualInferior->setInferior(nuevo);
				columnSetter = actualInferior->getSiguiente();
				actualInferior = actualInferior->getInferior();
				ultimo = actualInferior;
			}
		}
	}
}

void Lista::imprimir(string path)
{
	Nodo* actual = primero;
	Nodo* actualInferior = primero;
	Matriz obj(path);
	int columnas = obj.getColumnas();
	int filas = obj.getFilas();

	if (estaVacia())
	{
		cout << "Lista Vacia!";
		return;
	}
	else
	{
		while (actual != nullptr)
		{
			cout << "[ " << actual->getValor() << " ]";
			cout << ' ';
			actual = actual->getSiguiente();
			y++;
			if (y == columnas)
			{
				cout << '\n';
				actual = actualInferior->getInferior();
				actualInferior = actualInferior->getInferior();
				y = 0;
			}
		}
	}
}

void Lista::sumar(Lista a, Lista b, int col, string pathMC)
{
	Nodo* actualA = a.primero;
	Nodo* actualB = b.primero;
	Nodo* inferiorA = a.primero;
	Nodo* inferiorB = b.primero;
	int control = 0;
	int suma = 0;
	string nameMatrizC;
	ofstream fileC;
	Lista c;


	fileC.open(pathMC, ios_base::app);
	while (actualA != nullptr)
	{
		suma = actualA->getValor() + actualB->getValor();
		cout << "[ " << suma << " ]";
		fileC << "[ " << suma << " ]";
		c.agregar(suma, pathMC);
		actualA = actualA->getSiguiente();
		actualB = actualB->getSiguiente();
		control++;

		if (control == col)
		{
			cout << '\n';
			fileC << '\n';
			actualA = inferiorA->getInferior();
			inferiorA = inferiorA->getInferior();
			actualB = inferiorB->getInferior();
			inferiorB = inferiorB->getInferior();
			control = 0;
		}
	}
	fileC << "\n\n";
	fileC.close();
	return;
}

void Lista::restar(Lista a, Lista b, int col, string pathMC)
{
	Nodo* actualA = a.primero;
	Nodo* actualB = b.primero;
	Nodo* inferiorA = a.primero;
	Nodo* inferiorB = b.primero;
	int control = 0;
	int resta = 0;
	ofstream fileC;
	fileC.open(pathMC, ios_base::app);
	Lista c;

	while (actualA != nullptr)
	{
		resta = actualA->getValor() - actualB->getValor();
		cout << "[ " << resta << " ]";
		fileC << "[ " << resta << " ]";
		c.agregar(resta, pathMC);
		actualA = actualA->getSiguiente();
		actualB = actualB->getSiguiente();
		control++;

		if (control == col)
		{
			cout << '\n';
			fileC << '\n';
			actualA = inferiorA->getInferior();
			inferiorA = inferiorA->getInferior();
			actualB = inferiorB->getInferior();
			inferiorB = inferiorB->getInferior();
			control = 0;
		}
	}
	fileC << "\n\n";
	fileC.close();
	return;
}

void Lista::multiplicar(Lista a, Lista b, int filasA, int columnasB, string pathMC)
{
	Nodo* actualA = a.primero;
	Nodo* inferiorA = a.primero;
	Nodo* actualB = b.primero;
	Nodo* inferiorB = b.primero;
	int x = 0, z = 0, y = 0;
	int multiplicacion = 0;
	int resultado = 0;

	ofstream fileC;
	fileC.open(pathMC, ios_base::app);
	Lista c;

	while (z < (filasA * columnasB * filasA))
	{
		if (x < filasA)
		{
			multiplicacion = (actualA->getValor()) * (actualB->getValor());
			resultado += multiplicacion;
			actualA = actualA->getSiguiente();
			actualB = actualB->getInferior();
			x++;
			z++;
		}
		else
		{
			if (y < columnasB)
			{
				y++;
				cout << "[ " << resultado << " ]";
				fileC << "[ " << resultado << " ]";
				actualA = inferiorA;
				actualB = inferiorB->getSiguiente();
				inferiorB = inferiorB->getSiguiente();
				if (y == columnasB)
				{
					cout << '\n';
					fileC << '\n';
					actualB = b.primero;
					inferiorB = b.primero;
					inferiorA = inferiorA->getInferior();
					actualA = inferiorA;
					y = 0;
				}
				x = 0;
				resultado = 0;

			}
			else
			{
				cout << '\n';
				fileC << '\n';
				cout << "[ " << resultado << " ]";
				fileC << "[ " << resultado << " ]";
				inferiorA = inferiorA->getInferior();
				actualA = inferiorA;
				y = 0;
			}

		}
	}
	cout << "[ " << resultado << " ]";
	fileC << "[ " << resultado << " ]";
	fileC.close();
	return;
}

int Lista::determinante(Lista a, int filasA, int columnasA)
{
	Nodo* actual = a.primero;
	int multiplicacion = 1, multiplicacion2 = 1, multiplicacion3 = 1;
	int multiResult = 0, multiResult2 = 0;
	int resultado = 0;
	bool check = true;

	int control = 3;

	if (filasA == columnasA)
	{
		if (filasA == 2)
		{
			multiplicacion = actual->getValor() * actual->getSiguiente()->getInferior()->getValor();
			multiplicacion2 = actual->getSiguiente()->getValor() * actual->getInferior()->getValor();
			resultado = multiplicacion - multiplicacion2;
			return resultado;
		}
		else if (filasA == 3)
		{
			multiplicacion = actual->getValor() * (actual->getSiguiente()->getInferior()->getValor()) * (actual->getSiguiente()->getSiguiente()->getInferior()->getInferior()->getValor());
			multiplicacion2 = actual->getSiguiente()->getValor() * (actual->getSiguiente()->getSiguiente()->getInferior()->getValor()) * (actual->getInferior()->getInferior()->getValor());
			multiplicacion3 = actual->getSiguiente()->getSiguiente()->getValor() * (actual->getInferior()->getValor()) * (actual->getSiguiente()->getInferior()->getInferior()->getValor());
			multiResult = multiplicacion + multiplicacion2 + multiplicacion3;

			multiplicacion = actual->getInferior()->getInferior()->getValor() * (actual->getSiguiente()->getInferior()->getValor()) * (actual->getSiguiente()->getSiguiente()->getValor());
			multiplicacion2 = actual->getInferior()->getInferior()->getSiguiente()->getValor() * (actual->getInferior()->getSiguiente()->getSiguiente()->getValor()) * (actual->getValor());
			multiplicacion3 = actual->getSiguiente()->getSiguiente()->getInferior()->getInferior()->getValor() * (actual->getInferior()->getValor() * actual->getSiguiente()->getValor());
			multiResult2 = multiplicacion + multiplicacion2 + multiplicacion3;
			resultado = multiResult - multiResult2;
			return resultado;
		}
	}
	else
	{
		return -123456789;
	}
}

bool Lista::isIrregular(Lista a, int filas, int columnas)
{
	Nodo* actual = a.primero;
	Nodo* actualInferior = a.primero;

	int colFil = columnas * filas;
	int control = 1;
	int controlFil = 0;
	int controlCol = 0;

	while (actual != nullptr)
	{
		actual = actual->getSiguiente();
		if (controlCol < columnas - 1 && actual != nullptr)
		{

			controlCol++;
			control++;
		}
		else
		{
			if (controlFil < filas - 1)
			{
				controlFil++;
				actual = actualInferior->getInferior();
				actualInferior = actualInferior->getInferior();
				controlCol = 0;
				control++;
			}
		}
	}
	if (control == colFil)
	{
		return false;
	}
	else
	{
		return true;
	}

}