#include <iostream>

using namespace std;

#include <iostream>
#include <algorithm>

using namespace std;

struct Aula
{
    long long inicio;
    long long fin;
};

bool comparar(const Aula& a, const Aula& b)
{
    return a.inicio < b.inicio;
}

bool esPosible(Aula* aulas, int M, int N, long long D)
{
    long long ultimo = -(long long)1e18;
    long long estudiantes = 0;

    for (int i = 0; i < M; i++)
    {
        long long primeraPos = max(aulas[i].inicio, ultimo + D);

        if (primeraPos > aulas[i].fin)
        {
            continue;
        }

        long long cantidad =
            (aulas[i].fin - primeraPos) / D + 1;

        estudiantes += cantidad;

        if (estudiantes >= N)
        {
            return true;
        }

        ultimo = primeraPos + (cantidad - 1) * D;
    }

    return false;
}

int busquedaBinaria(int* lista, int tam)
{
    if (*lista != 1)
    {
        return 1;
    }
    int izq = 0;
    int der = tam-1;
    while (izq <= der)
    {
        int medio = (der + izq) / 2;
        if (*(lista + medio) == medio +1)
        {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    return izq + 1;
}



int main()
{
    int N, M;
    cin >> N >> M;

    Aula* aulas = new Aula[M];

    for (int i = 0; i < M; i++)
    {
        cin >> aulas[i].inicio >> aulas[i].fin;
    }

    sort(aulas, aulas + M, comparar);

    long long izq = 1;
    long long der = aulas[M - 1].fin - aulas[0].inicio;
    long long respuesta = 1;

    while (izq <= der)
    {
        long long medio = izq + (der - izq) / 2;

        if (esPosible(aulas, M, N, medio))
        {
            respuesta = medio;
            izq = medio + 1;
        }
        else
        {
            der = medio - 1;
        }
    }

    cout << respuesta << endl;

    delete[] aulas;

    return 0;
    /*
    int lista[8]={2,3,4,5,6,7,8,9};
    int tam = sizeof(lista) / sizeof(*lista);
    cout << "Falta: " << busquedaBinaria(lista, tam) << endl;
    return 0;
    */
}