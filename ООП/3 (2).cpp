#include <iostream>
#include <fstream>
#include <cstdlib> // äëÿ èñïîëüçîâàíèÿ ôóíêöèè exit()
#include <algorithm>
using std::ios;

int main()
{
	srand(time(NULL));

	std::fstream f("f.bin", ios::out | ios::binary);
	std::fstream g("g.bin", ios::out | ios::binary);

	// ÈÍÈÖÈÀËÈÇÀÖÈß ÌÀÑÑÈÂÀ È ÅÃÎ ÇÀÏÎËÍÅÍÈÅ
	const int arr_size = 6;
	int array[6];
	for (size_t i = 0; i < arr_size; ++i) {
		std::cin >> array[i]; // ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min
	}
	// ÇÀÏÈÑÜ Â ÔÀÉË f
	if (f.is_open()) {
		for (size_t i = 0; i < arr_size; ++i)
		{
			f.write(reinterpret_cast<char*>(&array), sizeof(array));
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "File f is opened" << std::endl;
	}
	// ÑÎĞÒÈĞÎÂÊÀ ÌÀÑÑÈÂÀ 
	std::sort(array, array + arr_size);

	int i = 0, j = 1;
	while (j < arr_size) {
		if (array[i] % 2 == 0 && array[j] % 2 != 0) {
			std::swap(array[i], array[j]);
			i += 2;
			j += 2;
		}
		else {
			j++;
		}
	}

	// ÇÀÏÈÑÜ Â ÔÀÉË g
	if (g.is_open()) {
		for (size_t i = 0; i < arr_size; ++i)
		{
			g.write(reinterpret_cast<char*>(&array[i]), sizeof(array));
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "File g is opened" << std::endl;
	}
	else
	{
		std::cerr << "File could not be opened!" << std::endl;
		exit(1);
	}

	f.close();
	g.close();
	return 0;
}
