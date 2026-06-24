#include "../.h/Hoja.h"


Hoja::Hoja(int dato)
{
    this->dato = dato;
    this->anterior = nullptr;
    this->mayorNext = nullptr;
    this->menorNext = nullptr;
}

Hoja::Hoja()
{
    this->anterior = nullptr;
    this->mayorNext = nullptr;
    this->menorNext = nullptr;
}

Hoja::~Hoja()
{
}

int Hoja::getDato()
{
    return dato;
}

void Hoja::setDato(int newDato)
{
    dato = newDato;
}

Hoja* Hoja::getAnterior()
{
    return anterior;
}

void Hoja::setAnterior(Hoja* newAnterior)
{
    anterior = newAnterior;
}

Hoja* Hoja::getMayorNext()
{
    return mayorNext;
}

void Hoja::setMayorNext(Hoja* newMayorNext)
{
    mayorNext = newMayorNext;
}

Hoja* Hoja::getMenorNext()
{
    return menorNext;
}

void Hoja::setMenorNext(Hoja* newMenorNext)
{
    menorNext = newMenorNext;
}