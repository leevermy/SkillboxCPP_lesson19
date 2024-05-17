#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file_path = ".\\Q&A\\1.txt";

    std::string line;

    std::ifstream file(file_path);
    while(getline(file, line)) {
        std::cout << line;
    }

    return 0;
}