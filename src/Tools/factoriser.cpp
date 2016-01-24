
#include "factoriser.h"

vector<long> factorise(long long number, long smallestPotentialPrime);

bool Factoriser::hasFactorIn(int number, vector<int> factors) {
    for (vector<int>::iterator it = factors.begin(); it != factors.end(); ++it) {
        if (number % *it == 0) {
            return true;
        }
    }
    
    return false;
}

vector<long> Factoriser::factorise(long long number) {
    vector<long> primeFactors;
    long factor = 0;
    long long numberWithoutFactor = number;
    
    for(long i = 2; i * i <= numberWithoutFactor; ++i) {
        while (numberWithoutFactor % i == 0) {
            factor = i;
            numberWithoutFactor = numberWithoutFactor / factor;
            primeFactors.push_back(factor);
        }
    }
    
    if (numberWithoutFactor > 1) {
        primeFactors.push_back(numberWithoutFactor);
    }
    
    return primeFactors;
}

vector<long> Factoriser::divisorsFor(long number) {
    vector<long> numberOfDivisors;
    
    
    long i;
    for (i = 1; i * i <= number; ++i) {
        if (number % i == 0) {
            numberOfDivisors.push_back(i);
            numberOfDivisors.push_back(number / i);
        }
    }
    
    if (i * i == number) {
        numberOfDivisors.pop_back();
    }
    
    return numberOfDivisors;
}
