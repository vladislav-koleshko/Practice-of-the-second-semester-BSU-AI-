#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> merge(std::vector<int>a, std::vector<int>b)
{
	std::vector<int>c;
	int x = 0;
	for (int i = 0; i < std::min(a.size(), b.size()); i++) {
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	for (int i = std::min(a.size(), b.size()); i < std::max(a.size(), b.size()); i++) {
		if (a.size() > b.size()) {
			c.push_back(a[i]);
		}
		else {
			c.push_back(b[i]);
		}
	}
	return c;
}

int main() {
	std::vector <int> array1 = { 4,1,2,3 };
	std::vector <int> array2 = { 6,5,7 };

	std::vector <int> array3;
	array3 = merge(array1, array2);

	int size3 = array3.size();


	int min_index = 0, max_index = 0;
	for (size_t i = 0; i < size3; ++i) {
		if (array3[i] < array3[min_index]) {
			min_index = i;
		}
		if (array3[i] > array3[max_index]) {
			max_index = i;
		}
	}
	for (auto const& element : array3)
		std::cout << element << " ";
	std::cout << std::endl;
	std::cout << min_index << " " << max_index << std::endl;

	for (size_t i = 0; i < size3; ++i) {
		std::swap(array3[min_index], array3[max_index]);
	}

	for (auto const& element : array3)
		std::cout << element << " ";
	return 0;
}