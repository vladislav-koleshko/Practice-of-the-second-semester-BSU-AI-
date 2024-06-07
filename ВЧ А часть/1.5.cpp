#include <iostream>

int func(int n);
int rec_func(int n);


int main() {
    int n;
    std::cin >> n;
    std::cout << func(n) << "\n";
    std::cout << rec_func(n) << " ";
    return 0;
}

int func(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        a = a + b;
        b = a - b;
    }
    return a;
}

int rec_func(int n) {
    if (n == 0) return (0);
    if (n == 1) return (1);
    return rec_func(n - 1) + rec_func(n - 2);
}