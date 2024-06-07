#include <iostream>
#include <vector>
#include <algorithm>

using vector2d = std::vector<std::vector<int>>;

void out(const vector2d& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void in(vector2d& vec, int m)
{
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec[i].size(); j++)
            vec[i][j] = rand() % m;
}


int main() {
    srand(time(NULL));

    int SIZE;
    std::cout << "Enter the size of MATRIX: ";
    std::cin >> SIZE;
    std::cout << std::endl;

    vector2d Matrica(SIZE, std::vector <int>(SIZE, 0));

    in(Matrica, 10);
    out(Matrica);

    std::vector<int> saveSum;
    for (int j = 0; j < SIZE; ++j) {
        int sumJ = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            sumJ += Matrica[i][j];
        }
        saveSum.push_back(sumJ);
    }

    int min;

    std::sort(saveSum.begin(), saveSum.end());
    min = saveSum[0];

    std::cout << min;

    return 0;
}