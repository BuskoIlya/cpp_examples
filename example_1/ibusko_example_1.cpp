﻿#include <clocale>
#include <ctime>
#include <iostream>
#include <utility>

void print_array(const wchar_t* const comment, const int* const arr, const int n);

int main() {
    std::setlocale(LC_ALL, "Russian");

    int arr_size;
    std::wcout << L"Введите размер массива: ";
    std::cin >> arr_size;

    int* arr = new int[arr_size];
    srand(time(0));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 10;
    }

    print_array(L"Был сгенерирован массив:", arr, arr_size);

    {
        bool even_condition;
        bool odd_condition;
        for (int i = 1; i < arr_size - 1; i++) {
            even_condition = !(i % 2 == 0 && arr[i] > arr[i - 1]);
            odd_condition = !(i % 2 != 0 && arr[i] < arr[i - 1]);
            if (even_condition && odd_condition) {
                std::swap(arr[i], arr[i - 1]);
            }
        }
    }

    print_array(L"Массив после обработки:", arr, arr_size);

    delete[] arr;
    return 0;
}

void print_array(const wchar_t* const comment, const int* const arr, const int n) {
    const char space = ' ';
    std::wcout << comment;
    for (int i = 0; i < n; i++) {
        std::cout << space << arr[i];
    }
    std::cout << std::endl;
}
