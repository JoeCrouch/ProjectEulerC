//http://projecteuler.net/problem=7

#include "problem7.h"
#include "primeCalculator.h"
#include <iostream>

using std::cout;
using std::endl;

bool isPrimeProblem7(int n);

const Problem7 Problem7::INSTANCE = Problem7();

void Problem7::run() const {
    int primeCount = 0, number = 2, primeNumber = 0;
    
    while (primeCount < 10001) {
        if (PrimeCalculator::isPrime(number)) {
            primeNumber = number;
            primeCount = primeCount + 1;
        }
        number++;
    }
    
    cout << "The 10,001st prime number is:" << endl;
    cout << primeNumber << endl << endl;
}
