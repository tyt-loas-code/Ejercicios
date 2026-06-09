#include "../h/Nodo.h"

Nodo::Nodo(int i,int v)
{
    indice = i;
    valor = v;
    siguiente = nullptr;
}

Nodo::~Nodo()
{
}

Nodo* Nodo::getSiguiente()
{
    return siguiente;
}

void Nodo::setSiguiente(Nodo* newSiguiente)
{
    siguiente = newSiguiente;
}

int Nodo::getIndice()
{
    return indice;
}

void Nodo::setIndice(int newIndice)
{
    indice = newIndice;
}

int Nodo::getValor()
{
    return valor;
}

void Nodo::setValor(int newValor)
{
    valor= newValor;
}