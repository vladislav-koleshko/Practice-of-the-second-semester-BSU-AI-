#include <iostream>
#include <time.h>

// функции заполнения массива
void random(const int n, int arr[]);
void ascending(const int n, int arr[]);
void descending(const int n, int arr[]);

// функции сортировки массива
int swapSort(const int n, int arr[]);
int selectionSort(const int n, int arr[]);

int main() {
	srand(time(NULL));

	const int n = 5;
	int array[n] = { 0 };

	// способ заполнение массива

	int ch = 0;
	std::cout << "Enter the way to fill array: " << std::endl << "1. Random" << std::endl << "2. Ascending" << std::endl << "3. Descending" << std::endl;
	std::cin >> ch;
	switch (ch)
	{
	case 1:
		random(n, array);
		break;
	case 2:
		ascending(n, array);
		break;
	case 3:
		descending(n, array);
		break;
	default:
		std::cout << "The wrong choice!";
		return 0;
	}

	// способ сортировки массива

	int ch1 = 0;
	std::cout << "Enter the way to sort array: " << std::endl << "1. Selection sort" << std::endl << "2. Swap sort" << std::endl;
	std::cin >> ch1;
	switch (ch1)
	{
	case 1:
		selectionSort(n, array);
		break;
	case 2:
		swapSort(n, array);
		break;
	default:
		std::cout << "The wrong choice!";
		return 0;
	}

	return 0;
}

void random(const int n, int arr[]) {
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void ascending(const int n, int arr[]) {
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void descending(const int n, int arr[]) {
	for (int i = n - 1; i >= 0; --i) {
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int swapSort(const int n, int arr[]) {
	int swapped = 0;
	int compared = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
		{
			compared++;
			if (arr[j] > arr[j + 1]) {
				/*int temp = arr[j];
				arr[j] == arr[j + 1];
				arr[j + 1] == temp;*/
				std::swap(arr[j], arr[j + 1]);
				swapped++;
			}
		}
	for (int i = 0; i < n; i++) {
		std::cout << std::endl;
		std::cout << arr[i] << " " << std::endl;
	}

	std::cout << "Amount of swaps: " << swapped << std::endl << "Amount of compare: " << compared;
	return arr[n];
}

int selectionSort(const int n, int arr[]) {
	int min = 0;
	int temp = 0;
	int swapped = 0;
	int compared = 0;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		compared++;
		for (int j = i + 1; j < n; j++) {
			min = (arr[j] < arr[min]) ? j : min;
		}
		if (i != min)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
			swapped++;
		}

	}
	for (int i = 0; i < n; ++i) {
		std::cout << std::endl;
		std::cout << arr[i] << " " << std::endl;
	}
	std::cout << "Amount of swaps: " << swapped << std::endl << "Amount of compare: " << compared;
	return arr[n];
}