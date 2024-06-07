#include <iostream> 
#include <list> 
#include <string> 
#include <fstream> 
#include <sstream> 

int main()
{
    const char* path = "in.txt";
    std::ifstream infile(path);
    std::string input;
    std::list <std::string> words;

    if (infile.is_open()) {
        while (std::getline(infile, input)) { std::cout << input; }
    }
    else { std::cout << "Couldn't open file for reading!"; return -1; }
    infile.close();

    std::stringstream ss(input);
    std::string word;

    while (ss >> word) {
        if (word.substr(0, 1) == "a" && word.size() >= 1)
            words.push_back(word);
    }

    std::ofstream outfile("out.txt");
    if (outfile.is_open()) {
        for (auto c : words)
            outfile << " " << c;
    }
    else { std::cout << "Couldn't open file for writing!"; return -1; }
    outfile.close();

    return 0;
}
