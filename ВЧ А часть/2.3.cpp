#include <iostream>
#include <stack>
#include <string>

int main() {
	std::stack<std::string> stack;
    std::string input;
    std::cout << "Enter your string: ";
    getline(std::cin, input);

    std::string word;
    std::string separators = " .,:;?!-()";

    for (size_t i = 0; i < input.size(); ++i) {
        if (separators.find(input[i])==std::string::npos) {
            word += input[i];
        }
    }
    while (!stack.empty()) {
        std::cout << " " << stack.top();
        stack.pop();
    }
    return 0;
}
