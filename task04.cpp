#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::cout << "Enter the path to the file: ";
    std::string filePath;
    std::cin >> filePath;

    std::ifstream file(filePath, std::ios::binary);
    if(!file.is_open()) {
        std::cerr << "Failed to open file " << filePath << std::endl;
        return 1;
    }

    unsigned char first_symbols[4];
    file.read((char*)first_symbols, sizeof(first_symbols));
    if (!file) {
        if (file.gcount() < 4) {
            std::cerr << "Failed to read data - file is too short." << std::endl;
        } else {
            std::cerr << "Failed to read data." << std::endl;
        }
        return 1;
    }

    file.close();

    if (first_symbols[0] == 137 && first_symbols[1] == 'P' && 
        first_symbols[2] == 'N' && first_symbols[3] == 'G') {
        std::cout << "This file is a PNG file." << std::endl;
    } else {
        std::cout << "This is not a PNG file." << std::endl;
    }

    return 0;
}