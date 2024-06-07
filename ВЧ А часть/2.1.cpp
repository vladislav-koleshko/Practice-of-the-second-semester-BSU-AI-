#include <iostream>

int main() {
	int n, k;
	std::cout << "Enter the k: ";
	std::cin >> k;
	std::cout << "Enter the size of array: ";
	std::cin >> n;
	int* array = new int[n];

	for (size_t i = 0; i < n; ++i) {
		array[i] = i;
		std::cout << array[i] << " " << "\n";
	}

	for (size_t i = 0; i < n; ++i) {
		array[i] = i - k;
		std::cout << array[i] << " ";
	}
	delete[] array;
	return 0;
}