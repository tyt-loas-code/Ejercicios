#include "../h/ArrayDisperso.h"
#include "../h/Nodo.h"

ArrayDisperso::ArrayDisperso(int cap)
{
    capacidad = cap;

    tabla = new Nodo*[capacidad];

    for(int i = 0; i < capacidad; i++)
    {
        *(tabla +i) = nullptr;
    }
}

ArrayDisperso::~ArrayDisperso()
{
    for(int i = 0; i < capacidad; i++)
    {
        Nodo* aux = *(tabla + i);

        while(aux)
        {
            Nodo* temp = aux;
            aux = aux->getSiguiente();
            delete temp;
        }
    }

    delete[] tabla;
}

int ArrayDisperso::hash(int indice)
{
    return indice % capacidad;
}

void ArrayDisperso::set(int indice, int valor)
{
    int pos = hash(indice);
    Nodo* actual = *(tabla + pos);
    while(actual)
    {
        if(actual->getIndice() == indice)
        {
            actual->setValor(valor);
            return;
        }
        actual = actual->getSiguiente();
    }
    Nodo* nuevo = new Nodo(indice, valor);
    nuevo->setSiguiente(*(tabla + pos));
    *(tabla + pos) = nuevo;
}

int ArrayDisperso::get(int indice)
{
    int pos = hash(indice);
    Nodo* actual = *(tabla + pos);
    while (actual)
    {
        if (actual->getIndice() == indice)
        {
            return actual->getValor();
        }
        actual = actual->getSiguiente();
    }

    return 0;
}