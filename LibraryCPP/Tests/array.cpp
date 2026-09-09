#include <iostream>
#include "array.h"

using namespace std;

int main()
{
    Array *arr = array_create(10);

    if (array_size(arr) != 10)
    {
        cout << "Неверный размер массива\n";
        array_delete(arr);
        return 1;
    }

    for (int i = 0 ; i < 10 ; ++i)
        array_set(arr, i, i * 2);

    for (int i = 0 ; i < 10 ; ++i)
    {
        if (array_get(arr, i) != i * 2)
        {
            cout << "Неверное значение элемента " << i << "\n";
            array_delete(arr);
            return 1;
        }
    }

    array_delete(arr);
}
