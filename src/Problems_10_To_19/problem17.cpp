//http://projecteuler.net/problem=17

#include "problem17.h"
#include "transformer.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const Problem17 Problem17::INSTANCE = Problem17();

void Problem17::run() const {
    string stringOfNumbersAsWords = "";
    
    for (int i = 1; i < 1001; ++i) {
        stringOfNumbersAsWords += Transformer::numberAsWord(i);;
    }
    
    cout << "The number of total letters used in 1 to 1000 as words is: " << stringOfNumbersAsWords.size() << endl << endl;
}




