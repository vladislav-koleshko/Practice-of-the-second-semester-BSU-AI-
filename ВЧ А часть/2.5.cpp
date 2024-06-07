#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
std::list<T> symmetric_difference(std::list<T>& L1, std::list<T>& L2) {
    L1.sort();
    L2.sort();

    std::list<T> L;

    std::set_symmetric_difference(L1.begin(), L1.end(), L2.begin(), L2.end(), std::inserter(L, L.begin()));

    return L;
}

int main() {
    std::list<int> L1 = { 1, 2, 3, 4, 5 };
    std::list<int> L2 = { 4, 5, 6, 7, 8 };

    std::list<int> L = symmetric_difference(L1, L2);

    std::cout << "L: ";
    for (int i : L) {
        std::cout << i << ' ';
    }
    return 0;
}
