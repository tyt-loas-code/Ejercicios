#include <iostream>
#include <functional>

using namespace std;

std::function<void(int*, int, int)> shellSort = [](int* inicio, int tam, int salto)
{
    if (salto <= 0){
        return;
    }
    for (int* i = inicio + salto; i < inicio + tam ; i++)
    {
        int temp = *i;
        int* j = i;

        while (j >= inicio + salto && *(j - salto) > temp)
        {
            *j = *(j - salto);
            j -= salto;
        }
        *j = temp;
    }
    shellSort(inicio, tam, salto/2);
};

void tresSumas(int* arreglo, int n, int target)
{
    shellSort(arreglo,n,n/2);
    for (int i = 0; i < n-2; i++)
    {
        int izq = i + 1;
        int der = n - 1;
        while (izq < der)
        {
            int suma = *(arreglo + i) + *(arreglo + izq) + *(arreglo +der);
            if (suma == target)
            {
                cout << "(" << *(arreglo + i) << ") + (" << *(arreglo + izq) << ") + (" << *(arreglo + der) << ") = " << suma << endl;
                izq++;
                der--;
            }
            else if (suma < target)
            {
                izq++;
            }
            else
            {
                der--;
            }
        }
    }
}

int main()
{
    int vec[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(vec) / sizeof(vec[0]);
    tresSumas(vec,n,0);
}