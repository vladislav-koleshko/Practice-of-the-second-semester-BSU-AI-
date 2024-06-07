#pragma once

template <typename T>
class MyVector {
private:
    const size_t size;
    T* data;

public:


    MyVector() { }


    MyVector(T value) : data(new T[]) {}


    MyVector(const MyVector& vector) : data(new T(*vector.data)) {}


    MyVector(const MyVector&& vector) noexcept : data(vector.data) {
        vector.data = nullptr;
    }


    ~MyVector() {
        delete[] data;
        data = nullptr;
        size = 0;
    }


    T& getElement(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Error: Index is out of range\n";
            exit(EXIT_FAILURE);
        }
        return data[index];
    }

    void setElement(int index, double value) {
        if (index < 0 || index >= size) {
            std::cerr << "Error: Index is out of range\n";
            exit(EXIT_FAILURE);
        }
        data[index] = value;
    }

    void scalarOperation(double scalar, char operation) {
        switch (operation) {
        case '+':
            for (auto& el : data) el += scalar;
            break;
        case '-':
            for (auto& el : data) el -= scalar;
            break;
        case '*':
            for (auto& el : data) el *= scalar;
            break;
        case '/':
            if (scalar == 0) {
                std::cerr << "Error: Divide on 0\n";
                exit(EXIT_FAILURE);
            }
            for (auto& el : data) el /= scalar;
            break;
        default:
            std::cerr << "Error: Wrong operation\n";
            exit(EXIT_FAILURE);
        }
    }

    double length() const {
        double sum = 0;
        for (const auto& el : data) sum += el * el;
        return sqrt(sum);
    }

    void elementwiseOperation(const MyVector& other, char operation) {
        if (size() != other.size) {
            std::cerr << "Error: Vectors of different size\n";
            exit(EXIT_FAILURE);
        }
        switch (operation) {
        case '+':
            for (int i = 0; i < size; ++i) data[i] += other.data[i];
            break;
        case '-':
            for (int i = 0; i < size; ++i) data[i] -= other.data[i];
            break;
        case '*':
            for (int i = 0; i < size; ++i) data[i] *= other.data[i];
            break;
        case '/':
            for (int i = 0; i < size; ++i) {
                if (other.data[i] == 0) {
                    std::cerr << "Error: Divide on 0\n";
                    exit(EXIT_FAILURE);
                }
                data[i] /= other.data[i];
            }
            break;
        default:
            std::cerr << "Error: Wrong operation\n";
            exit(EXIT_FAILURE);
        }
    }

    void printVector() const {
        for (const auto& el : data) std::cout << el << ' ';
        std::cout << '\n';
    }

    void inputVector() {
        for (auto& el : data) std::cin >> el;
    }

    void randomFill() {
        for (auto& el : data) el = rand() % 100 + 1;
    }

};