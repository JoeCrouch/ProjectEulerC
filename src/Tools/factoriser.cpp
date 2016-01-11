
#include <stdio.h>
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
    long smallestPrime = 2;
    return ::factorise(number, smallestPrime);
}

vector<long> factorise(long long number, long smallestPotentialPrime) {
    vector<long int> primeFactors;
    long d = 0;
    
    //TODO: could use sieve of eras once extracted
    for(long i = smallestPotentialPrime; i * i < number; ++i) {
        if (number % i == 0) {
            d = i;
            break;
        }
    }
    
    if (d == 0) {
        primeFactors.push_back(number);
        return primeFactors;
    }
    
    primeFactors.push_back(d);
    vector<long int> otherFactors = factorise(number/d, d + 1);
    
    primeFactors.insert(primeFactors.end(), otherFactors.begin(), otherFactors.end());
    return primeFactors;
}
