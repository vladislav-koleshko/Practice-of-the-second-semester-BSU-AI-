#include <iostream>
#include <algorithm>

int** enterArray(int** array, int size);
void printArray(int** array, int size);
int** fillArray(int** array, int size);

int main() {
	int n;
	std::cout << "Enter the size of array: ";
	std::cin >> n;

	int** array = new int* [n];
	for (size_t i = 0; i < n; ++i) {
		array[i] = new int[n];
	}

	fillArray(array, n);
	printArray(array, n);

	for (size_t i = 0; i < n; ++i) {
		delete[] array[i];
	}
	delete[] array;
	return 0;
}

int** enterArray(int** array, int size) {
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j) {
			std::cin >> array[i][j];
		}
	return array;
}

void printArray(int** array, int size) {
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int** fillArray(int** array, int size) {
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			array[i][j] = i + 1;
		}
	}
	return array;
}