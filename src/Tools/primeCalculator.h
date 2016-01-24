
#ifndef ProjectEulerC_primeCalculator_h
#define ProjectEulerC_primeCalculator_h

#include <vector>

using std::vector;

class PrimeCalculator {
    
public:
    static bool isPrime(long n);
    static vector<int> buildVectorOfPrimesBelow(long upperBound);
    
private :
    PrimeCalculator() {};
};

#endif
