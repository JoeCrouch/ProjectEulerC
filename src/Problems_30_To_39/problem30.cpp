//http://projecteuler.net/problem=30

#include "problem30.h"
#include "transformer.h"
#include "calculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

const Problem30 Problem30::INSTANCE = Problem30();

void Problem30::run() const {
    int upperBound = 354294; // this is 6 * 9^5
    int sum = 0;
    
    vector<int> fifthPowersOfDigits;
    
    for (int i = 0; i < 10; ++i) {
        fifthPowersOfDigits.push_back(Calculator::powerOf(i, 5));
    }
    
    for (int i = 2; i <= upperBound; ++i) {
        vector<int> asVector = Transformer::asVector(i);
        
        int sumOfDigitsToFifthPower = 0;
        for (vector<int>::iterator it = asVector.begin(); it != asVector.end(); ++it) {
            sumOfDigitsToFifthPower += fifthPowersOfDigits[*it];
            if (sumOfDigitsToFifthPower > i) {
                break;
            }
        }
        
        if (sumOfDigitsToFifthPower == i) {
            sum += i;
        }
    }
    
    cout << "Sum of numbers whose digits to the power of 5 sum to make the number is: " << sum << endl << endl;
}

