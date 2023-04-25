//
//  main.cpp
//  kmp
//
//  Created by Ling, Chenyi (Fed) on 4/25/23.
//
//
#include "kmp_serial.hpp"
#include <iostream>

int main() {
    std::string text = "1234567890abcdefg";
    std::string pattern = "g";

    kmp kmp_search(pattern);

    try {
        std::vector<int> match_positions = kmp_search.searchIn(text);

        std::cout << "Matched positions: ";
        for (int pos : match_positions) {
            std::cout << pos << " " <<std::endl;
        }
        std::cout << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

