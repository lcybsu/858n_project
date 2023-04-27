//
//  main.cpp
//  kmp
//
//  Created by Ling, Chenyi (Fed) on 4/25/23.
//
//
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include "kmp_serial.hpp"

#include <omp.h>
#include <string>


int main() {
//    std::string text = "1234567890abcdefg";

    std::string file_name = "/Users/cnl29/Desktop/kmp/kmp/kmp/bird.txt"; // Replace with the name of your text file
    std::ifstream file(file_name);
    std::string text;

     if (file.is_open()) {
         std::stringstream buffer;
         buffer << file.rdbuf();
         text = buffer.str();
         file.close();
     } else {
         std::cerr << "Unable to open the file: " << file_name << std::endl;
         return 1;
     }

    std::string pattern = "CATCATTAATA";

    kmp kmp_search(pattern);

    try {
        auto start = std::chrono::high_resolution_clock::now(); // Start timer

        std::vector<int> match_positions = kmp_search.searchIn(text);

        auto end = std::chrono::high_resolution_clock::now(); // End timer
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // Calculate duration

        std::cout << "Matched positions: ";
        for (int pos : match_positions) {
            std::cout << pos << " " << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Time taken: " << duration << " microseconds" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

