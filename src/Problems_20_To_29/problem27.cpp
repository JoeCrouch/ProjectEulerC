//http://projecteuler.net/problem=27

#include "problem27.h"
#include "primeCalculator.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

int numberOfQuadraticsWithPrimeResult(int number1, int number2);

const Problem27 Problem27::INSTANCE = Problem27();

void Problem27::run() const {
    int max = 1000;
    vector<int> primes = PrimeCalculator::buildVectorOfPrimesBelow(max);
    
    int totalMax = 0;
    long productProducingMax = 0;
    
    for (int i = max - 1; i > 0; --i) {
        // b must be prime and therefore positive.
        for (vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
            
            int maxForPositive = numberOfQuadraticsWithPrimeResult(i, *it);
            if (maxForPositive > totalMax) {
                totalMax = maxForPositive;
                productProducingMax = i * *it;
            }
            
            int maxForNegative = numberOfQuadraticsWithPrimeResult(-i, *it);
            if (maxForNegative > totalMax) {
                totalMax = maxForNegative;
                productProducingMax = -i * *it;
            }
        }
    }
    
    cout << "The product of coefficients producing longest prime chain is: " << productProducingMax << endl << endl;
}

int numberOfQuadraticsWithPrimeResult(int number1, int number2) {
    int n = 1;
    int count = 1;
    long number = n * n + number1 * n + number2;
    
    while (PrimeCalculator::isPrime(number)) {
        n++;
        count++;
        number = n * n + number1 * n + number2;
    }
    
    return count;
}

