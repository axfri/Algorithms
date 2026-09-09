#include "array.h"

struct Array
{
    Data *data;
    size_t size;
};

// Создание массива
Array *array_create(size_t size)
{
    return new Array{new Data[size](), size};
}

// Удаление массива и освобождение памяти
void array_delete(Array *arr)
{
    if (arr == nullptr)
        return;

    delete[] arr->data;
    delete arr;
}

// Получение элемента массива
Data array_get(const Array *arr, size_t index)
{
    if (arr == nullptr || index >= arr->size)
        return Data();

    return arr->data[index];
}

// Изменение элемента массива
void array_set(Array *arr, size_t index, Data value)
{
    if (arr == nullptr || index >= arr->size)
        return;

    arr->data[index] = value;
}

// Получение размера массива
size_t array_size(const Array *arr)
{
    return arr == nullptr ? 0 : arr->size;
}
