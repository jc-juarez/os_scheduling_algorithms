/*****************************************
*  OS Scheduling Algorithms - Refactoring
*  'main.cpp'
*  Author: Juan Carlos Juárez
*  Contact: jc.juarezgarcia@outlook.com
*****************************************/ 

#include <iostream>
#include <string>
#include <utility>
#include <random>
#include "scheduling_algorithms.hpp"

#define FIFO_OPTION 1
#define LRU_OPTION 2
#define EXIT_OPTION 3
#define STRING_SIZE 10
#define NUMBER_OF_PAGES 5

int main() {

    // Option for Selecting Algorithm or Quitting
    int option{};

    std::cout << "\n*** OS Scheduling Algorithms ***\n\n";

    // Generate Generator Seed for Random Numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(0, 10);

    do {

        // Generate Random String of Processes
        static std::string random_string{};
        random_string = "";
        for(int i = 0; i < STRING_SIZE; ++i) {
            char random_char = 'a' + distr(gen);
            random_string += random_char;
        }

        std::cout << "The Randomly Generated String of Processes is: " << random_string << "\n\n";
        std::cout << "Options: \n\n";
        std::cout << "1) FIFO\n";
        std::cout << "2) LRU\n";
        std::cout << "3) Exit\n\n";
        std::cout << "Select the Algorithm to perform over the Process String: ";
        std::cin >> option;

        if(option == FIFO_OPTION || option == LRU_OPTION) {

            std::pair<int,double> result{};
            result = option == FIFO_OPTION ? os_scheduling::FIFO(random_string, NUMBER_OF_PAGES) : os_scheduling::LRU(random_string, NUMBER_OF_PAGES);

            std::cout << "\n- Page Frame Fails: " << result.first << "\n";
            std::cout << "- Efficiency: " << result.second << "%" << "\n\n";

        } else if(option != EXIT_OPTION) {

            std::cout << "\nThe Specified Input was not a valid Option.\n\n";

        }

        if(option != EXIT_OPTION) std::cout << "*********************************************************\n\n";

    } while(option != EXIT_OPTION);

    std::cout << "\n";
    return 0;
}
