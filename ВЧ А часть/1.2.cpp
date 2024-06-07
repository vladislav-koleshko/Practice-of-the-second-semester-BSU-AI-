#include <iostream>
#include <cmath>

double calculate_polynomial(int n, double x) {
    return (9 - n) * pow(x, n) + pow(x, 8) + 2 * pow(x, 7) + 3 * pow(x, 6) + 4 * pow(x, 5) + 5 * pow(x, 4) + 6 * pow(x, 3) + 7 * pow(x, 2) + 8 * x + 9;
}

int main() {
    double x0 = 1;
    double xm = 2;
    double delta_x = 0.2;
    int n = 10;  //

    for (double x = x0; x <= xm; x += delta_x) {
        double z = calculate_polynomial(n, x);
        std::cout << "x: " << x << ", z: " << z << std::endl;
    }

    return 0;
}
