
#include "Nodo.h"

Nodo::Nodo() :valor(-1), siguiente(nullptr), inferior(nullptr) {}

Nodo::Nodo(int _valor, Nodo* _siguiente, Nodo* _inferior)
{
	setValor(_valor);
	setSiguiente(_siguiente);
	setInferior(_inferior);
}

void Nodo::setValor(int _valor)
{
	this->valor = _valor;
}

int Nodo::getValor(void)
{
	return this->valor;
}

void Nodo::setSiguiente(Nodo* _sig)
{
	this->siguiente = _sig;
}

Nodo* Nodo::getSiguiente(void)
{
	return this->siguiente;
}

void Nodo::setInferior(Nodo* _inf)
{
	this->inferior = _inf;
}

Nodo* Nodo::getInferior(void)
{
	return this->inferior;
}
