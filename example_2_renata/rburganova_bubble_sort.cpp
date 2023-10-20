#include <ctime>
#include <iostream>

// Camel case <- google
// Если в каждой функции используется size, то его стоит писать впереди/сзади всегда
void BubbleSort(const int size, int array[]);
void RandomArr(const int size, int array[]);
void StdSort(const int size, const int unsorted_arr[], int std_array[]);
void Test(const int size, const int bubblesort_array[], const int std_array[]);

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 10; // const
    int arr[size]; // Создаем массив в main, тк иначе он пропадет из стека после завершения функции (RandomArr)
    int std_arr[size];
    RandomArr(size, arr);
    StdSort(size, arr, std_arr);
    BubbleSort(size, arr);
    Test(size, arr, std_arr);
}

void BubbleSort(const int size, int array[]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void RandomArr(const int size, int array[]) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 30;
    }
    std::wcout << L"Сгенерированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void StdSort(const int size, const int unsorted_arr[], int std_array[]) {
    for (int i = 0; i < size; i++) {
        std_array[i] = unsorted_arr[i];
    }
    std::sort(std_array, std_array + size);
}

void Test(const int size, const int bubblesort_array[], const int std_array[]) {
    // Нам не нужна bool result
    for (int i = 0; i < size; i++) {
        if (bubblesort_array[i] != std_array[i]) {
            std::wcout << L"Результаты не сошлись";
            return;
        }
    }
    std::wcout << L"Результаты сошлись" << std::endl;
}




