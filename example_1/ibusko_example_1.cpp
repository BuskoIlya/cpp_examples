#include <ctime>
#include <iostream>

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

    std::wcout << L"Был сгенерирован массив:";
    for (int i = 0; i < arr_size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    for (int i = 1; i < arr_size - 1; i++) {
        if (!(((i % 2 == 0) && (arr[i] >= arr[i - 1])) || ((i % 2 != 0) && (arr[i] <= (arr[i - 1]))))) {
            std::swap(arr[i], arr[i - 1]);
        }
    }

    std::wcout << L"Массив после обработки:";
    for (int i = 0; i < arr_size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    delete[] arr;
}
