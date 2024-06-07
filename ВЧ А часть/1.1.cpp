#include <iostream>
#include <limits.h>

int max_degree(signed short number);
void max_degree_pointer(signed short* number);
void max_degree_link(signed short& number);

int main() {
    signed short number = SHRT_MAX;
    max_degree(number);
    std::cout << std::endl;
    max_degree_pointer(&number);
    std::cout << std::endl;
    max_degree_link(number);
    return 0;
}

int max_degree(signed short number) {
    int count = 0;

    while (number != 0) {
        number = number / 7;
        count++;
    }
    std::cout << count * 2;
    return count * 2;
}

void max_degree_pointer(signed short* number) {
    int count = 0;
    int num;
    num = *number;
    while (num != 0) {
        num = num / 7;
        count++;
    }
    std::cout << count * 2;
}

void max_degree_link(signed short& number) {
    int count = 0;

    while (number != 0) {
        number = number / 7;
        count++;
    }
    std::cout << count * 2;
}