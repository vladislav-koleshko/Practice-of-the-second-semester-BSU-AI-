#include <iostream>

int** createAndFillArr_FirstWay(int rows, int cols) {
	int** arr = new int* [rows];

	for (size_t i = 0; i < rows; ++i) {
		arr[i] = new int[cols];
	}

	std::cout << "Enter the first array: " << "\n";
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			std::cin >> arr[i][j];
		}
	}
	return arr;
}

int* createAndFillArr_SecondWay(int rows, int cols) {
	int* arr = new int[rows * cols];

	std::cout << "Enter the second array: " << "\n";
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			std::cin >> arr[i * cols + j];
		}
	}
	return arr;
}

void processArr_FirstWay(int** arr, int rows, int cols) {
	bool Found = false;
	for (size_t j = 0; j < cols; ++j) {
		bool isEven = true;
		for (size_t i = 0; i < rows; ++i) {
			if (arr[i][j] % 2 != 0) {
				isEven = false;
				break;
			}
		}
		if (isEven) {
			std::cout << "Column with even elements has a number: " << j + 1 << '\n';
			Found = true;
		}
	}
	if (!Found)
		std::cout << "There is no columns with even elements :(" << '\n';
}

void processArr_SecondWay(int* arr, int rows, int cols) {
	bool Found = false;
	for (size_t j = 0; j < cols; ++j) {
		bool isEven = true;
		for (size_t i = 0; i < rows; ++i) {
			if (arr[i * cols + j] % 2 != 0) {
				isEven = false;
				break;
			}
		}
		if (isEven) {
			std::cout << "Column with even elements has a number: " << j + 1 << '\n';
			Found = true;
		}

	}
	if (!Found)
		std::cout << "There is no columns with even elements :(";
}

int main() {
	int cols, rows;
	std::cout << "Enter rows count: ";
	std::cin >> rows;
	std::cout << "Enter cols count: ";
	std::cin >> cols;

	int** arr = createAndFillArr_FirstWay(rows, cols);

	processArr_FirstWay(arr, rows, cols);

	int* array = createAndFillArr_SecondWay(rows, cols);

	processArr_SecondWay(array, rows, cols);

	for (size_t i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}