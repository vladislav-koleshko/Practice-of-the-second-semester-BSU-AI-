#include <iostream> 
#include <stack> 
#include <string> 
#include <fstream> 
#include <sstream> 

int main()
{
    const char* path = "in.txt";
    std::ifstream infile(path);
    std::string input;
    std::stack <std::string> words;

    if (infile.is_open()) {
        while (std::getline(infile, input)) { std::cout << input; }
    }
    else { std::cout << "Couldn't open the file for reading!"; return -1; }
    infile.close();

    std::stringstream ss(input);
    std::string word;

    while (ss >> word) {
        words.push(word);
    }

    std::ofstream outfile("out.txt");
    if (outfile.is_open()) {
        while (!words.empty()) {
            outfile << words.top() << " ";
            words.pop();
        }
    }
    else { std::cout << "Couldn't open the file for writing!"; return -1; }
    outfile.close();

    return 0;
}
