#include "Matriz.h"
#include "Nodo.h"
#include "Lista.h"
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<stdio.h>

using namespace std;

Matriz::Matriz(void) {}

Matriz::Matriz(string _path)
{
	this->path = _path;
}


Lista Matriz::createMatrix(void)
{
	ifstream file;
	string line;
	int x = 0;
	string valor;
	Lista lista;
	file.open(path);


	if (file.fail())
	{
		cout << "Unable to open file!";
		exit(1);
	}
	else
	{
		while (!file.eof())
		{
			getline(file, line);
			//cout << line << endl;

			while (x < line.size())
			{
				if (line.at(x) != ' ')
				{
					valor += line.at(x);
					x++;
				}
				else
				{
					lista.agregar(std::atoi(valor.c_str()), path);
					valor = "";
					x++;
				}
			}
			if (x != 0)
			{

				lista.agregar(std::atoi(valor.c_str()), path);

			}
			x = 0;
			valor = "";
		}
		file.close();
	}
	return lista;
}

int Matriz::getFilas()
{
	ifstream file;
	string line;
	int filas = 0;
	file.open(path);

	if (file.fail())
	{
		cout << "Direccion de archivo incorrecta";
		return -1;
	}
	else
	{

		while (!file.eof())
		{
			getline(file, line);
			filas++;
		}
	}

	return filas;
}

int Matriz::getColumnas()
{
	ifstream file;
	string line;
	int x = 0;
	int columnas = 0;
	bool check = true;

	file.open(path);

	if (file.fail())
	{
		cout << "Direccion de Archivo incorrecta";
		return -1;
	}
	else
	{
		getline(file, line);

		if (check == true)
		{
			while (x < line.size())
			{
				if (line.at(x) == ' ')
				{
					columnas++;
				}
				x++;
			}
			check = false;
		}
		return columnas = columnas + 1;
	}
}

void Matriz::setPath(string _path)
{
	this->path = _path;
}

string Matriz::getPath(void)
{
	return this->path;
}

void Matriz::sumar(Matriz A, Matriz B)
{
	Lista a;
	Lista b;
	string nameMatrizC;
	a = A.createMatrix();
	b = B.createMatrix();
	cout << "Matriz A\n";
	a.imprimir(A.getPath());
	cout << '\n';
	cout << "Matriz B\n";
	b.imprimir(B.getPath());

	if (a.isIrregular(a, A.getFilas(), A.getColumnas()) == false && b.isIrregular(b, B.getFilas(), B.getColumnas()) == false)
	{
		if (A.getFilas() == B.getFilas() && A.getColumnas() == B.getColumnas())
		{
			cout << "\nIngrese el nombre con el que se guardara la Matriz C: ";
			cin >> nameMatrizC;
			cout << '\n';
			cout << "Matriz C\n";
			a.sumar(a, b, A.getColumnas(), nameMatrizC + ".dat");
		}
		else
		{
			cout << "\nMatrices son de diferentes tamaños!";
		}
	}
	else
	{
		cout << "\nUna de la matrices es irregular";
	}

	return;
}

void Matriz::restar(Matriz A, Matriz B)
{
	Lista a;
	Lista b;
	string nameMatrizC;
	a = A.createMatrix();
	b = B.createMatrix();
	cout << "Matriz A\n";
	a.imprimir(A.getPath());
	cout << '\n';
	cout << "Matriz B\n";
	b.imprimir(B.getPath());

	if (a.isIrregular(a, A.getFilas(), A.getColumnas()) == false && b.isIrregular(b, B.getFilas(), B.getColumnas()) == false)
	{
		if (A.getFilas() == B.getFilas() && A.getColumnas() == B.getColumnas())
		{
			cout << "\nIngrese el nombre con el que se guardara la Matriz C: ";
			cin >> nameMatrizC;
			cout << '\n';
			cout << "Matriz C\n";
			a.restar(a, b, A.getColumnas(), nameMatrizC + ".dat");
		}
		else
		{
			cout << "\nMatrices son de diferentes tamaños!";
		}
	}
	else
	{
		cout << "\nUna de la matrices es irregular";
	}
	return;
}

void Matriz::multiplicar(Matriz A, Matriz B)
{
	Lista a;
	Lista b;
	a = A.createMatrix();
	b = B.createMatrix();

	string nameMatrizC;

	if (a.isIrregular(a, A.getFilas(), A.getColumnas()) == false && b.isIrregular(b, B.getFilas(), B.getColumnas()) == false)
	{
		cout << "Matriz A\n";
		a.imprimir(A.getPath());
		cout << '\n';
		cout << "Matriz B\n";
		b.imprimir(B.getPath());

		if (A.getColumnas() == B.getFilas())
		{
			cout << "\nIngrese el nombre con el que se guardara la Matriz C: ";
			cin >> nameMatrizC;
			cout << '\n';
			cout << "Matriz C\n";
			a.multiplicar(a, b, A.getFilas(), B.getColumnas(), nameMatrizC + ".dat");
		}
		else
		{
			cout << "Columnas de MATRIZ A no coinciden con Filas de MATRIZ B";
		}
	}
	else
	{
		cout << "Una de la matrices es irregular";
	}
	return;
}

int Matriz::determinante(Matriz A, int filasA, int columnasA)
{
	Lista a;
	a = A.createMatrix();
	a.imprimir(A.getPath());

	if (A.getColumnas() == A.getFilas() && a.isIrregular(a, A.getFilas(), A.getColumnas()) == false)
	{
		cout << "\nDeterminante de la Matriz: ";
		return a.determinante(a, filasA, columnasA);
	}
	else
	{
		cout << "La Matriz ingresada is irregular!";
		return 0;
	}

}





