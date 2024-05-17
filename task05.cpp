#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <filesystem>
#include <algorithm>

std::string ReadFile(const std::filesystem::path & file_path);

int main() {
    const int total_sectors = 13;
    bool sectors[total_sectors];
    std::fill_n(sectors, total_sectors, true);

    int sector = 1;

    int player_points = 0;
    int audience_points = 0;

    while (player_points < 6 && audience_points < 6) {
        int offset;
        std::cout << "\nEnter the offset (displacement) for rotating the top: ";
        std::cin >> offset;

        sector = (sector + offset) % total_sectors;
        if(sector == 0) sector = 13;

        while(!sectors[sector - 1]) {
            sector = (sector % total_sectors) + 1;
        }
        sectors[sector - 1] = false;

        std::filesystem::path question_path = "./Q&A/question-" + std::to_string(sector) + ".txt";
        std::filesystem::path answer_path = "./Q&A/answer-" + std::to_string(sector) + ".txt";;
        
        std::string question = ReadFile(question_path);
        std::string answer = ReadFile(answer_path);
        std::transform(answer.begin(), answer.end(), answer.begin(), [](unsigned char ch) {
            return std::toupper(ch);
        });


        std::cout << "The question from " << sector << " envelope\n" << std::endl;
        std::cout << question; 
        
        std::cout << "\nEnter your answer: ";
        std::string player_answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, player_answer);
        std::transform(player_answer.begin(), player_answer.end(), player_answer.begin(), [](unsigned char ch) {
            return std::toupper(ch);
        });


        if (player_answer == answer) {
            std::cout << "Your answer is correct. You got 1 point" << std::endl;
            ++player_points;
        } else {
            std::cout << "Wrong. Audience got 1 point" << std::endl;
            ++audience_points;
        }
    }

    if (player_points >= 6) {
        std::cout << "Player won" << std::endl;
    } else {
        std::cout << "Audience won" << std::endl;
    }
    return 0;
}

std::string ReadFile(const std::filesystem::path & file_path) {
    std::ifstream file(file_path);
    
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << file_path << std::endl;
        return "";
    }
    char buffer [1024];
    std::string content = "";
    while(!file.eof()) {
        file.read(buffer, sizeof(buffer) - 1);
        buffer[file.gcount()] = '\0';
        std::string line(buffer);
        content += line;
    }
    file.close();
    return content;
}
