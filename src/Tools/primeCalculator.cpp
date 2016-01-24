
#include "primeCalculator.h"

bool PrimeCalculator::isPrime(long n) {
    if (n <= 1) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    } else if (n < 9) {
        return true;
    } else if (n % 3 == 0) {
        return false;
    } else if (n % 5 == 0) {
        return false;
    } else {
        for (int i = 7; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

vector<int> PrimeCalculator::buildVectorOfPrimesBelow(long upperBound) {
    vector<int> primes;
    
    if (upperBound < 2) {
        return primes;
    } else {
        primes.push_back(2);
    }
    
    vector<int> potentialPrimes;
    //Creates a vector containing 3,5,7....
    for (int i = 3; i < upperBound; i += 2) {
        primes.push_back(i);
    }
    
    //Removes the non prime elements of the vector using sieve of Eratosthenes: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    for (int i = 1; i < primes.size() / 2; ++i) {
        if (primes[i] == 0) {
            continue;
        }
        
        for (int j = (3 * i + 1); j < primes.size(); j += (2 * i + 1)) {
            primes[j] = 0;
        }
    }
    
    primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());
    
    
    return primes;
}
