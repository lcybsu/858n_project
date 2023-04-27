//
//  kmp_serial.hpp
//  kmp
//
//  Created by Ling, Chenyi (Fed) on 4/25/23.
//

#ifndef kmp_serial_hpp
#define kmp_serial_hpp

#include <iostream>
#include <list>
#include <string>
#include <vector>

class kmp {
public:
    kmp();
    kmp(const std::string& pattern);
    ~kmp();
    void setPatternStr(const std::string& pattern);
    std::vector<int> searchIn(const std::string& text);
    
protected:
    void getNextArray();
    void getNextArray2();
    std::string _patternStr;    // pattern string
    int   _lenOfPattern;        // length of pattern string
    std::vector<int> _nextArray; // next array for pattern string
};

#endif /* kmp_serial_hpp */
