#include <iostream>
#include <string>
#include <queue>

int main() {
    std::queue<std::string> result;
    std::string input;
    std::cout << "Enter your string: ";
    getline(std::cin, input);

    std::string word;
    std::string separators = " .,:;?!-()";

    for (size_t i = 0; i < input.size(); ++i) {
        if (separators.find(input[i]) == std::string::npos) {
            word += input[i];
        }
        else {
            if (word.size() >= 3 && word.substr(word.size() - 3) == "xyz") {
                result.push(word);
            }
            word = "";
        }
    }

    // Проверка последнего слова
    if (!word.empty() && word.size() >= 3 && word.substr(word.size() - 3) == "xyz") {
        result.push(word);
    }

    while (!result.empty()) {
        std::cout << ' ' << result.front();
        result.pop();
    }
    return 0;

}
