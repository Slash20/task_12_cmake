#include <func.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip> 
#include <sstream>  

namespace TimeLogger {

    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        std::stringstream formattedTime;
        formattedTime << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S");

        return formattedTime.str();
    }

    void logStartTime(const std::string& filePath) {
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open()) {

            int currentRunNumber = 0;
            std::ifstream inputFile(filePath);
            if (inputFile.is_open()) {
                std::string line;
                while (std::getline(inputFile, line)) {
                    currentRunNumber++;
                }
                inputFile.close();
            }

            file << currentRunNumber + 1 << " " << getCurrentTime() << std::endl;
            file.close();
        }
        else {
            std::cout << "File not open!" << std::endl;
        }
    }

}
