#if !defined(__Arboles_Arbol_h)
#define __Arboles_Arbol_h

#include "Hoja.h"
#include <iostream>

class Arbol
{
private:
    Hoja* raiz;
public:
    void insertarHoja(int);
    void imprimirArbol(Hoja*);
    int alturaArbol(Hoja*);

    Hoja* getRaiz();
    void setRaiz(Hoja*);

    Arbol();
    ~Arbol();
};

#endif