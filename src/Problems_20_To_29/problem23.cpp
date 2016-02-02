//http://projecteuler.net/problem=23

#include "problem23.h"
#include "calculator.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

vector<int> getAbundantNumbers();

const Problem23 Problem23::INSTANCE = Problem23();

void Problem23::run() const {
    vector<int> abundantNumbers = getAbundantNumbers();
    bool sumOfAbundants [28124] = {false};
    
    for (int i = 0; i < abundantNumbers.size(); ++i) {
        int firstNumber = abundantNumbers[i];
        for (int j = i; j < abundantNumbers.size(); ++j) {
            int sum = firstNumber + abundantNumbers[j];
            
            if (sum > 28124) {
                break;
            } else {
                sumOfAbundants[sum] = true;
            }
        }
    }
    
    long sum = 0;
    
    for (int i = 1; i < 28124; ++i) {
        if (!sumOfAbundants[i]) {
            sum += i;
        }
    }
    
    cout << "The sum of numbers that cannot be formed by the sum of 2 abundant numbers is: " << sum << endl << endl;
}

vector<int> getAbundantNumbers() {
    vector<int> abundantNumbers;
    
    for (int i = 12; i < 28124; ++i) {
        long sumOfProperDivisors = Calculator::sumProperDivisors(i);
        if (sumOfProperDivisors > i) {
            abundantNumbers.push_back(i);
        }
    }
    
    return abundantNumbers;
}




