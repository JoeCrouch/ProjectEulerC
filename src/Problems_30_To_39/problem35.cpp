//http://projecteuler.net/problem=35

#include "problem35.h"
#include "primeCalculator.h"
#include "calculator.h"
#include "transformer.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::includes;
using std::find;
using std::sort;

vector<int> circularPrimesFor(int number);
int nextCircularNumber(int number, int lengthOfNumber);

vector<int> powersOfTen = {1};
vector<int> primes = PrimeCalculator::buildVectorOfPrimesBelow(1000000);

const Problem35 Problem35::INSTANCE = Problem35();

void Problem35::run() const {
    vector<int> circularPrimes;
    
    for (int power = 1; power < 6; ++power) {
        powersOfTen.push_back(Calculator::powerOf(10, power));
    }
    
    for (vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        if (find(circularPrimes.begin(), circularPrimes.end(), *it) != circularPrimes.end()) {
            continue;
        }
        
        vector<int> circularPrimesTemp = circularPrimesFor(*it);
        if (circularPrimesTemp.size() > 0) {
            circularPrimes.insert(circularPrimes.end(), circularPrimesTemp.begin(), circularPrimesTemp.end());
        }
    }
    
    cout << "Total Circular Primes Below 1 mill is: " << circularPrimes.size() << endl << endl;
}

vector<int> circularPrimesFor(int number) {
    vector<int> circularNumbers = {number};
    int length = Calculator::lengthOf(number);
    int circularNumber = nextCircularNumber(number, length);
    
    while (circularNumber != number) {
        if (!PrimeCalculator::isPrime(circularNumber)) {
            vector<int> empty;
            return empty;
        }
        
        circularNumbers.push_back(circularNumber);
        circularNumber = nextCircularNumber(circularNumber, length);
    }
    
    sort(circularNumbers.begin(), circularNumbers.end());
    return circularNumbers;
}

int nextCircularNumber(int number, int length) {
    int digits = number % 10;
    int nextCircularNumber = number / 10;
    
    nextCircularNumber += digits * powersOfTen[length - 1];
    
    return nextCircularNumber;
}


