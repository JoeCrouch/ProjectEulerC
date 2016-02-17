//http://projecteuler.net/problem=40

#include "problem40.h"
#include "calculator.h"
#include "transformer.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem40 Problem40::INSTANCE = Problem40();

int consecutiveDigitNumber(int n);

void Problem40::run() const {
    
    cout << endl
    << "The product of the digits that are 10^n where  0 <= n <= 6 of the consecutive numbers string is: "
    << consecutiveDigitNumber(1) * consecutiveDigitNumber(10) * consecutiveDigitNumber(100) * consecutiveDigitNumber(1000) * consecutiveDigitNumber(10000) * consecutiveDigitNumber(100000) * consecutiveDigitNumber(1000000)
    << endl
    << endl;
}

int consecutiveDigitNumber(int n) {
    int length = 1;
    int numbersWithLength = 9;
    int totalDigitLength = numbersWithLength * length;
    
    while (n > totalDigitLength) {
        n -= totalDigitLength;
        length++;
        numbersWithLength *= 10;
        totalDigitLength = numbersWithLength * length;
    }
    
    int number = 1 * Calculator::powerOf(10, length - 1);
    
    while (n > length) {
        number++;
        n -= length;
    }
    
    vector<int> vectorOfNumber = Transformer::asVector(number);
    
    return vectorOfNumber[n - 1];
}

