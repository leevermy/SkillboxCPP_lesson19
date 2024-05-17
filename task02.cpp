#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;             
    std::string line;

    std::cout << "Enter the path to the file: ";
    std::cin >> filePath;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filePath << std::endl;
        return 1;
    }

    //вариант без буфера
    // while (getline(file, line)) {
    //     std::cout << line << std::endl;
    // }

    const int buffer_size = 1024;
    char buffer[buffer_size];

    while(!file.eof()) {
        file.read(buffer, buffer_size - 1);
        buffer[file.gcount()] = '\0';
        std::cout << buffer;
    }

    file.close();
    return 0;
}