#include <iostream>
#include "../h/ArrayDisperso.h"

using namespace std;

int main()
{
    ArrayDisperso arreglo(101);

    arreglo.set(10,5);
    arreglo.set(5000,8);
    arreglo.set(9999,10);

    cout << arreglo.get(10) << endl;
    cout << arreglo.get(5000) << endl;
    cout << arreglo.get(20);

    return 0;
}