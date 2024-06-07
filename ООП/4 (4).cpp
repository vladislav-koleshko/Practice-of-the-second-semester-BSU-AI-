#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

class Vector {
private:
    static const size_t MAX_SIZE = 1000;
    size_t size;
    std::vector<float> elements;

public:

    Vector() : size(0), elements(std::vector<float>(MAX_SIZE, 0.0f)) {}


    Vector(size_t size) : size(size), elements(std::vector<float>(size, 0.0f)) {
        if (size > MAX_SIZE) {
            throw std::out_of_range("Размерность вектора превышает максимальный размер");
        }
    }


    Vector(const Vector& other) : size(other.size), elements(other.elements) {}


    Vector(Vector&& other) noexcept : size(other.size), elements(std::move(other.elements)) {
        other.size = 0;
    }


    ~Vector() = default;


    void setSize(size_t size) {
        if (size > MAX_SIZE) {
            throw std::out_of_range("Размерность вектора превышает максимальный размер");
        }
        this->size = size;
        elements.resize(size, 0.0f);
    }


    size_t getSize() const {
        return size;
    }


    float getElement(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы размерности вектора");
        }
        return elements[index];
    }


    void setElement(size_t index, float value) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы размерности вектора");
        }
        elements[index] = value;
    }


    Vector operator+(float scalar) const {
        Vector result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.elements[i] += scalar;
        }
        return result;
    }

    Vector operator-(float scalar) const {
        Vector result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.elements[i] -= scalar;
        }
        return result;
    }

    Vector operator*(float scalar) const {
        Vector result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.elements[i] *= scalar;
        }
        return result;
    }

    Vector operator/(float scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Деление на ноль");
        }
        Vector result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.elements[i] /= scalar;
        }
        return result;
    }


    float length() const {
        float sum = 0.0f;
        for (size_t i = 0; i < size; ++i) {
            sum += elements[i] * elements[i];
        }
        return std::sqrt(sum);
    }

    // Метод поэлементного сложения (вычитания, умножения, деления) векторов с одинаковыми границами индексов


    Vector operator-(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Векторы имеют разную размерность");
        }
        Vector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }


    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }


    void input() {
        for (size_t i = 0; i < size; ++i) {
            std::cin >> elements[i];
        }
    }


    void randomize(float minValue, float maxValue) {
        for (size_t i = 0; i < size; ++i) {
            elements[i] = minValue + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxValue - minValue)));
        }
    }

    static Vector combine(const Vector& x, const Vector& y, float a, float b) {
        if (x.size != y.size) {
            throw std::invalid_argument("Векторы имеют разную размерность");
        }
        Vector z(x.size);
        for (size_t i = 0; i < x.size; ++i) {
            z.elements[i] = a * x.elements[i] + b * y.elements[i];
        }
        return z;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.elements[i] << " ";
        }
        return os;
    }


    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            is >> vec.elements[i];
        }
        return is;
    }
};

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");

    Vector v1(5);
    std::cout << "Введите 5 элементов вектора: " << std::endl;
    std::cin >> v1;
    std::cout << "Вы ввели вектор: " << v1 << std::endl;

    Vector v2(5);
    v2.setElement(0, 5.0);
    v2.setElement(1, 4.0);
    v2.setElement(2, 3.0);
    v2.setElement(3, 2.0);
    v2.setElement(4, 1.0);
    v2.print();

    Vector v3 = Vector::combine(v1, v2, 1.0, 2.0);

    std::cout << "Vector v3: ";
    v3.print();

    return 0;
}

