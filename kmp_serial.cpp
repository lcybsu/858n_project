//
//  kmp_serial.cpp
//  kmp
//
//  Created by Ling, Chenyi (Fed) on 4/25/23.
//

#include "kmp_serial.hpp"
#include <cstring>
#include <stdexcept>

kmp::kmp(): _lenOfPattern(0) {
}

kmp::kmp(const std::string& pattern) {
    setPatternStr(pattern);
}

kmp::~kmp() {
}

// set pattern string
void kmp::setPatternStr(const std::string& pattern) {
    _patternStr = pattern;
    _lenOfPattern = pattern.length();
    getNextArray2();
}

// search pattern in text
std::vector<int> kmp::searchIn(const std::string& text) {
    if(text.empty()) {
        throw std::invalid_argument("Text is empty!");
    }
    if(_lenOfPattern == 0) {
        throw std::invalid_argument("Pattern string is empty!");
    }

    size_t j = 0;
    size_t i = 0;

    // store matched positions
    std::vector<int> matchPosList;

    // find all matched sub string
    while(i < text.length() && j < _lenOfPattern) {
        if(text[i] != _patternStr[j]) {
            if(_nextArray[j] < 0) {
                ++i;
            } else {
                j = _nextArray[j];
            }
        } else {
            ++i;
            ++j;
        }
        if(j == _lenOfPattern) {
            matchPosList.push_back(i - _lenOfPattern);
            j = _nextArray[j];
        }
    }
    return matchPosList;
}

// get next[...] array for pattern string
void kmp::getNextArray() {
    if(_patternStr.empty() || _lenOfPattern == 0) return;
    
    _nextArray.resize(_lenOfPattern);
    _nextArray[0] = -1;
    
    for(int i = 1; i < _lenOfPattern; i++) {
        int j;
        _nextArray[i] = 0;
        for(j = i - 1 ; j > 0; j--) {
            std::string str1 = _patternStr.substr(0, j);
            std::string str2 = _patternStr.substr(i-j, j);
            
            if(str1 == str2) {
                _nextArray[i] = j;
                break;
            }
        }
    }
}

void kmp::getNextArray2() {
    if (_patternStr.empty() || _lenOfPattern == 0) return;

    _nextArray.resize(_lenOfPattern + 1);
    _nextArray[0] = -1;
    _nextArray[1] = 0;
    int j = 2;

    while (j <= _lenOfPattern) {
        int i = _nextArray[j - 1];
        while (i != 0 && _patternStr[i] != _patternStr[j - 1]) {
            i = _nextArray[i];
        }
        _nextArray[j] = i + 1;
        if (j != _lenOfPattern) {
            if (_patternStr[j] != _patternStr[i + 1]) {
                _nextArray[j] = i + 1;
            } else {
                _nextArray[j] = _nextArray[i + 1];
            }
        }
        j = j + 1;
    }
}



