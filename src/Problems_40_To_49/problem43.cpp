//http://projecteuler.net/problem=43

#include "problem43.h"
#include "calculator.h"
#include "transformer.h"
#include "printer.h"
#include "primeCalculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

static bool isSubStringDivisible(vector<int> numberAsVector);

static vector<int> primes = PrimeCalculator::buildVectorOfPrimesBelow(18);

const Problem43 Problem43::INSTANCE = Problem43();

void Problem43::run() const {
    vector<int> numbers = {0,1,2,3,4,5,6,7,8,9};
    long factorial = Calculator::factorial(numbers.size());
    
    vector<int> sum = {0};
    vector<int> pandigitalNumber = numbers;
    long i = 1;
    while (i <= factorial) {
        
        if (isSubStringDivisible(pandigitalNumber)) {
            sum = Calculator::sumOfVectors(sum, pandigitalNumber);
        }
        
        pandigitalNumber = Calculator::getNextLexPermutation(pandigitalNumber);
        i++;
    }
    
    cout << "Sum of sub string divisble 0 to 9 pandigital numbers is: " << endl;
    Printer::vecPrint(sum);
    cout << endl << endl;
}

bool isSubStringDivisible(vector<int> numberAsVector) {
    if (numberAsVector[5] != 5) {
        return false;
    } else if (numberAsVector[3] % 2 != 0) {
        return false;
    }
    
    for (int i = 2; i < 8; ++i) {
        vector<int> subSet(numberAsVector.begin() + i, numberAsVector.begin() + i + 3);
        int asNumber = Transformer::asNumber(subSet);
        
        if (asNumber % primes[i - 1] != 0) {
            return false;
        }
        
        if (i == 2) {
            i++;
        }
    }
    
    return true;
}


