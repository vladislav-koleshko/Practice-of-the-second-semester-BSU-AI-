#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

double f1(double x) {
    return pow(x + 3, 3) - 8;
}

double df1(double x) {
    return 3 * pow(x + 3, 2);
}

double f2(double x, double s) {
    return cos(M_PI * x) - pow(x, s);
}

double df2(double x, double s) {
    return -M_PI * sin(M_PI * x) - s * pow(x, s - 1);
}

double newton(double (*f)(double, double), double (*df)(double, double), double x, double a, double b, double eps, int& k_iter) {
    double h = f(x, b) / df(x, b);
    while (fabs(h) >= eps) {
        h = f(x, b) / df(x, b);
        x = x - h;
        k_iter++;
    }
    return x;
}

double newton(double (*f)(double), double (*df)(double), double x, double eps, int& k_iter) {
    double h = f(x) / df(x);
    while (fabs(h) >= eps) {
        h = f(x) / df(x);
        x = x - h;
        k_iter++;
    }
    return x;
}

int main() {
    int k_iter = 0;
    double eps = 1e-6;
    double root = newton(f1, df1, -2, eps, k_iter);
    std::cout << "Root: " << root << ", Iterations: " << k_iter << ", f(x0): " << f1(root) << std::endl;

    k_iter = 0;
    root = newton((double (*)(double, double))f2, (double (*)(double, double))df2, 0, 2, 3, eps, k_iter);
    std::cout << "Root: " << root << ", Iterations: " << k_iter << ", f(x0): " << f2(root, 3) << std::endl;

    return 0;
}
