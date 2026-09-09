#include <fstream>
#include <iostream>

#include "array.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Использование: Lab1CPPMaxFiveSum входной_файл.txt\n";
        return 1;
    }

    ifstream input(argv[1]);
    if (!input)
    {
        cerr << "Ошибка: не удалось открыть входной файл\n";
        return 1;
    }

    int size;
    if (!(input >> size) || size < 5)
    {
        cerr << "Ошибка: размер массива должен быть не меньше 5\n";
        return 1;
    }

    Array *arr = array_create(size);

    for (int i = 0; i < size; ++i)
    {
        Data value;
        if (!(input >> value))
        {
            cerr << "Ошибка: в файле недостаточно элементов массива\n";
            array_delete(arr);
            return 1;
        }
        array_set(arr, i, value);
    }

    long long current_sum = 0;
    for (int i = 0; i < 5; ++i)
        current_sum += array_get(arr, i);

    long long maximum_sum = current_sum;
    int best_start = 0;

    for (int i = 5; i < size; ++i)
    {
        current_sum -= array_get(arr, i - 5);
        current_sum += array_get(arr, i);

        if (current_sum > maximum_sum)
        {
            maximum_sum = current_sum;
            best_start = i - 4;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (i > 0)
            cout << ' ';

        cout << array_get(arr, best_start + i);
    }
    cout << '\n';

    array_delete(arr);
    return 0;
}
