#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "words.txt"; 
    std::string searchWord;             
    std::string word;                  
    int count = 0;                      

    std::cout << "Enter the word to search for: ";
    std::cin >> searchWord;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    while (file >> word) {  
        if (word == searchWord) {
            count++;
        }
    }

    file.close();
    std::cout << "The word '" << searchWord << "' appears " << count << " times in the file." << std::endl;

    return 0;
}