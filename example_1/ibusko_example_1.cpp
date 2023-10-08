#include <iostream>
#include <ctime>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
        a[i] = rand();

    for (int i = 1; i < n - 1; i++)
        if (!(((i % 2 == 0) && (a[i] >= a[i - 1])) || ((i % 2 != 0) && (a[i] <= (a[i - 1])))))
            std::swap(a[i], a[i - 1]);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
}
