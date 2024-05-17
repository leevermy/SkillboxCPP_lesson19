#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::string filePath = "payments.txt";

    std::ifstream file(filePath);
    if(!file.is_open()) {
        std::cerr << "Failed to open file " << filePath << std::endl;
        return 1;
    }

    
    std::string first_name;
    std::string last_name;
    int salary;
    std::string date;

    int sum = 0;
    std::string max_name;

    int temp_salary = 0;
    std::string line;

    while(getline(file, line)) {
        std::stringstream str(line);
        str >> first_name >> last_name >> salary >> date;
        sum += salary;

        if (temp_salary < salary) {
            max_name = first_name + " " + last_name;
            temp_salary = salary;
        }
    }
    std::cout << "Total amount paid: " << sum << std::endl;
    std::cout << "Person with maximum payment: " << max_name << std::endl;
    return 0;
}