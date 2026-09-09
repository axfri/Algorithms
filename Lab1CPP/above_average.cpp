#include <fstream>
#include <iostream>

#include "array.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Использование: Lab1CPPAboveAverage входной_файл.txt\n";
        return 1;
    }

    ifstream input(argv[1]);
    if (!input)
    {
        cerr << "Ошибка: не удалось открыть входной файл\n";
        return 1;
    }

    int size;
    if (!(input >> size) || size <= 0)
    {
        cerr << "Ошибка: неверный размер массива\n";
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

    Data minimum = array_get(arr, 0);
    Data maximum = minimum;

    for (int i = 1; i < size; ++i)
    {
        Data value = array_get(arr, i);

        if (value < minimum)
            minimum = value;

        if (value > maximum)
            maximum = value;
    }

    long long doubled_average = static_cast<long long>(minimum) + maximum;
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (2LL * array_get(arr, i) > doubled_average)
            ++count;
    }

    cout << count;
    for (int i = 0; i < size; ++i)
    {
        if (2LL * array_get(arr, i) > doubled_average)
            cout << ' ' << i + 1;
    }
    cout << '\n';

    array_delete(arr);
    return 0;
}
