#ifndef NODO_H
#define NODO_H

class Nodo
{
private:
	int valor;
	Nodo* siguiente;
	Nodo* inferior;

public:

	Nodo(void);
	Nodo(int, Nodo*, Nodo*);

	void setSiguiente(Nodo*);
	Nodo* getSiguiente(void);

	void setValor(int);
	int getValor(void);

	void setInferior(Nodo*);
	Nodo* getInferior(void);
};

#endif
