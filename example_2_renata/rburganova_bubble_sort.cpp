#include <algorithm>
#include <ctime>
#include <iostream>

// TODO
// Перетащить main на самый верх
// Инициализировать функции
// Убрать Мусор (комменты и тд)
// Убрать ненужные библиотеки
// неизменяемые переменные сделать конст
// Отдельная функция генерации рандомного массива

int* bubbleSort(const int size, int* arr);
int* randomArr(const int size);
int* stdSort(int size, int* arr);
void test(const int* array, const int* array_copy, int size);


int main() {
    std::setlocale(LC_ALL, "Russian");

    int size = 10;

    test(bubbleSort(size, randomArr(size)), stdSort(size, randomArr(size)), size);
}

int* randomArr(const int size) {
    int array[size];
    srand(time(0));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 30;
    }
    std::wcout << L"Сгенерированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    return array;
}

int* stdSort(int size, int* arr) {
    int array_copy[size];
    for (int i = 0; i < size; i++) {
        array_copy[i] = arr[i];
    }
    std::sort(array_copy, array_copy + size);
    return array_copy;
}

int* bubbleSort(int size, int* array) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
    return array;
}

void test(const int* array, const int* array_copy, int size) {
    bool result = true;
    for (int i = 0; i < size; i++) {
        if (array[i] != array_copy[i]) {
            result = false;
        }
    }

    if (result == 1) {
        std::wcout << L"Результаты сошлись";
    }
    else {
        std::wcout << L"Результаты не сошлись";
    }
}




