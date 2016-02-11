//http://projecteuler.net/problem=37

#include "problem37.h"
#include "primeCalculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cerr;

bool isTruncatablePrime(int prime);

const Problem37 Problem37::INSTANCE = Problem37();

void Problem37::run() const {
    int upperLimit = 1000000;
    vector<int> primes = PrimeCalculator::buildVectorOfPrimesBelow(upperLimit);
    
    int truncatablePrimesCount = 0;
    int sum = 0;
    
    vector<int>::iterator primeIterator = primes.begin();
    while (truncatablePrimesCount < 11) {
        
        while (!isTruncatablePrime(*primeIterator)) {
            primeIterator++;
            if (primeIterator == primes.end()) {
                cerr << "Reached end of primes before getting to 11. Try greater upper limit" << endl;
            }
        }
        
        sum += *primeIterator;
        truncatablePrimesCount++;
        primeIterator++;
    }
    
    cout << "Sum of truncatable primes is: " << sum << endl << endl;
}

bool isTruncatablePrime(int prime) {
    if (prime < 10) {
        return false;
    }
    
    int rightToLeft = prime / 10;
    while (rightToLeft > 0) {
        if (!PrimeCalculator::isPrime(rightToLeft)) {
            return false;
        }
        rightToLeft /= 10;
    }
    
    int moduloValue = 10;
    int leftToRight = prime % moduloValue;
    while (leftToRight != prime) {
        if (!PrimeCalculator::isPrime(leftToRight)) {
            return false;
        }
        moduloValue *= 10;
        leftToRight = prime % moduloValue;
    }
    
    return true;
}




