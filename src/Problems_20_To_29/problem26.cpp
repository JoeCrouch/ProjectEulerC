//http://projecteuler.net/problem=26

#include "problem26.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::find;

vector<int> decimalsOfDivide(int numerator, int denominator);

const Problem26 Problem26::INSTANCE = Problem26();

void Problem26::run() const {
    int maxDenominator = 1000;
    long maxCycle = 0;
    int numberWithMaxCycle = 2;
    
    for (int i = 2; i < maxDenominator; ++i) {
        vector<int> decimalsUpToFirstCycle = decimalsOfDivide(1, i);
        long numberOfDecimals = decimalsUpToFirstCycle.size();
        
        if (maxCycle < numberOfDecimals) {
            maxCycle = numberOfDecimals;
            numberWithMaxCycle = i;
        }
    }
    
    cout << "Denominator of (1/d) less than 1000 with longest recurring cycle is: " << numberWithMaxCycle << endl << endl;
}

vector<int> decimalsOfDivide(int numerator, int denominator) {
    vector<int> decimals;
    vector<int> remainders;
    
    int remainder = numerator % denominator;
    int decimal = numerator / denominator;
    
    while (remainder != 0 && find(remainders.begin(), remainders.end(), remainder) == remainders.end()) {
        remainders.push_back(remainder);
        decimals.push_back(decimal);
        
        numerator = remainder * 10;
        remainder = numerator % denominator;
        decimal = numerator / denominator;
    }
    
    decimals.erase(decimals.begin());
    
    return decimals;
}

