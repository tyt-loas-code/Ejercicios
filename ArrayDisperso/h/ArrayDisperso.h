#ifndef ARRAYDISPERSO_H
#define ARRAYDISPERSO_H

#include "Nodo.h"

class ArrayDisperso
{
private:
    Nodo** tabla;
    int capacidad;
    int hash(int);
public:
    void set(int, int);
    int get(int);
    ArrayDisperso(int);
    ~ArrayDisperso();
};

#endif