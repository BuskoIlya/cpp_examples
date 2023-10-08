#include <iostream>
#include <ctime>

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    srand(time(0));

    for (int i = 0; i < n; i++)
        a[i] = rand();

    for (int i = 1; i < n - 1; i++)
        if (!(((i % 2 == 0) && (a[i] >= a[i - 1])) || ((i % 2 != 0) && (a[i] <= (a[i - 1])))))
            std::swap(a[i], a[i - 1]);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";

    delete[] a;
}
