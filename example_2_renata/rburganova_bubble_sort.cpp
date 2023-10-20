#include <algorithm>
#include <ctime>
#include <iostream>

void copy_array(const int* const arr, int* const copy_arr, const int n);
void init_array(int arr[], const int n);
bool is_equal_arrays(const int* const arr1, const int* const arr2, const int n);
void print_array(const wchar_t* const comment, const int* const arr, const int n);
void sort(int arr[], const int n);

int main() {
    setlocale(LC_ALL, "Russian");

    const int arr_size = 10;
    int arr[arr_size];
    int copy_arr[arr_size];

    init_array(arr, arr_size);
    print_array(L"Сгенерированный массив: ", arr, arr_size);

    copy_array(arr, copy_arr, arr_size);
    std::sort(copy_arr, copy_arr + arr_size);

    sort(arr, arr_size);
    bool is_equal = is_equal_arrays(arr, copy_arr, arr_size);
    if (is_equal) {
        std::wcout << L"Результаты сошлись" << std::endl;
    } else {
        std::wcout << L"Результаты не сошлись" << std::endl;
    }

    return 0;
}

void copy_array(const int* const arr, int* const copy_arr, const int n) {
    for (int i = 0; i < n; i++) {
        copy_arr[i] = arr[i];
    }
}

void init_array(int arr[], const int n) {
    srand(time(0));
    const int value_limit = 30;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % value_limit;
    }
}

bool is_equal_arrays(const int* const arr1, const int* const arr2, const int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void print_array(const wchar_t* const comment, const int* const arr, const int n) {
    const char space = ' ';
    std::wcout << comment;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << space;
    }
    std::cout << std::endl;
}

void sort(int arr[], const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
