#include <iostream>

template <typename T>
T func(T a) {
	return a;
}

int func_(int i) {
	return i;
}
float func_(float f) {
	return f;
}
double func_(double d) {
	return d;
}
char func_(char c) {
	return c;
}
void func_(int array[]) {
	
}

int main() {
	int i = func(5);
	std::cout << i << " ";
	char c = func('c');
	std::cout << c << " ";;
	float f = func(1.1);
	std::cout << f << " ";;
	double d = func(1.356);
	std::cout << d << " ";;
	return 0;
}