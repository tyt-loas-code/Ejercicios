#include "../.h/Arbol.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>

Arbol::Arbol()
{
    raiz = nullptr;
}

Arbol::~Arbol()
{
}

void Arbol::insertarHoja(int dato)
{
    Hoja* nuevo = new Hoja(dato);
    if (raiz == nullptr)
    {
        raiz = nuevo;
        return;
    }
    
    Hoja* actual = raiz;
    Hoja* padre = nullptr;

    while (actual != nullptr)
    {
        padre = actual;
        if (dato < actual->getDato())
        {
            actual = actual->getMenorNext();
        } else if (dato >= actual->getDato())
        {
            actual = actual->getMayorNext();
        }
    }

    if (padre->getDato() > dato)
    {
        padre->setMenorNext(nuevo);
    } else
    {
        padre->setMayorNext(nuevo);
    }
}

int Arbol::alturaArbol(Hoja* nodo)
{
    if (nodo == nullptr)
        return 0;

    int izq = alturaArbol(nodo->getMenorNext());
    int der = alturaArbol(nodo->getMayorNext());

    return 1 + (izq > der ? izq : der);
}

void Arbol::imprimirArbol(Hoja* raiz)
{
    if (raiz == nullptr) return;

    int altura = alturaArbol(raiz);
    
    // Cola para el recorrido por niveles (guardamos el nodo y su posición teórica)
    // Usamos un nodo "ficticio" con valor -1 para representar los huecos vacíos
    std::queue<Hoja*> cola;
    cola.push(raiz);

    int nivel_actual = 0;

    while (nivel_actual < altura) {
        int nodos_en_nivel = std::pow(2, nivel_actual);
        std::vector<Hoja*> nodos_linea;

        // 1. Extraer todos los nodos del nivel actual
        for (int i = 0; i < nodos_en_nivel; ++i) {
            Hoja* actual = cola.front();
            cola.pop();
            nodos_linea.push_back(actual);

            if (actual != nullptr) {
                cola.push(actual->getMayorNext());
                cola.push(actual->getMenorNext());
            } else {
                // Mantener la estructura simétrica insertando nulos simulados
                cola.push(nullptr);
                cola.push(nullptr);
            }
        }

        // 2. Calcular espaciados matemáticos para este nivel
        int espacio_entre = std::pow(2, altura - nivel_actual + 1) - 2;
        int espacio_inicial = std::pow(2, altura - nivel_actual) - 1;

        // 3. Imprimir los NÚMEROS del nivel
        std::cout << std::string(espacio_inicial, ' ');
        for (size_t i = 0; i < nodos_linea.size(); ++i) {
            if (nodos_linea[i] != nullptr) {
                std::cout << std::setw(2) << nodos_linea[i]->getDato();
            } else {
                std::cout << "  "; // Espacio vacío si no hay nodo
            }
            if (i < nodos_linea.size() - 1) {
                std::cout << std::string(espacio_entre, ' ');
            }
        }
        std::cout << "\n";

        // 4. Imprimir las RAMAS (/ \) si no es el último nivel
        if (nivel_actual < altura - 1) {
            std::cout << std::string(espacio_inicial - 1, ' ');
            for (size_t i = 0; i < nodos_linea.size(); ++i) {
                if (nodos_linea[i] != nullptr) {
                    std::cout << (nodos_linea[i]->getMayorNext() ? "/" : " ");
                    std::cout << "  ";
                    std::cout << (nodos_linea[i]->getMenorNext() ? "\\" : " ");
                } else {
                    std::cout << "    ";
                }
                if (i < nodos_linea.size() - 1) {
                    std::cout << std::string(espacio_entre - 2, ' ');
                }
            }
            std::cout << "\n";
        }

        nivel_actual++;
    }
}

Hoja* Arbol::getRaiz()
    {
        return raiz;
    }
void Arbol::setRaiz(Hoja* newRaiz)
{
    raiz = newRaiz;
}