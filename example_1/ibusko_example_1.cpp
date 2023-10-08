#include <ctime>
#include <iostream>

int main() {
    int arr_size;
    std::cin >> arr_size;

    int* arr = new int[arr_size];
    srand(time(0));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand();
    }

    for (int i = 1; i < arr_size - 1; i++) {
        if (!(((i % 2 == 0) && (arr[i] >= arr[i - 1])) || ((i % 2 != 0) && (arr[i] <= (arr[i - 1]))))) {
            std::swap(arr[i], arr[i - 1]);
        }
    }

    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}
