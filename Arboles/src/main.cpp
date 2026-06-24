#include <iostream>
#include "../.h/Arbol.h"

using namespace std;

int main()
{
    Arbol* arbol = new Arbol();
    int datos[]={12,20,23,14,11,30,5};
    int tam = sizeof(datos) / sizeof(datos[0]);

    for (int i = 0; i < tam; i++)
    {
        arbol->insertarHoja(*(datos + i));
    }
    arbol->imprimirArbol(arbol->getRaiz());

    return 0;
}
