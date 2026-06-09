#ifndef NODO_H
#define NODO_H

class Nodo
{
private:
    int indice;
    int valor;
    Nodo* siguiente;

public:
    Nodo* getSiguiente();
    void setSiguiente(Nodo*);
    int getIndice();
    void setIndice(int);
    int getValor();
    void setValor(int);
    Nodo(int,int);
    ~Nodo();
};


#endif