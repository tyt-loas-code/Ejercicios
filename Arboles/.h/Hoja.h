#ifndef HOJA_H
#define HOJA_H

class Hoja
{
private:
    int dato;
    Hoja* anterior;
    Hoja* mayorNext;
    Hoja* menorNext;
public:
    int getDato();
    void setDato(int);

    Hoja* getAnterior();
    void setAnterior(Hoja*);

    Hoja* getMayorNext();
    void setMayorNext(Hoja*);

    Hoja* getMenorNext();
    void setMenorNext(Hoja*);

    Hoja(int);
    Hoja();
    ~Hoja();
};
#endif