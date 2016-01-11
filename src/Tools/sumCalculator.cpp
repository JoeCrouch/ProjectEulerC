
#include "sumCalculator.h"
#include "factoriser.h"

/*
 * Calculates the sum of all integers less than @upTo that have at least one factor in @factors. 
 */
int SumCalculator::sumMulitplesOf(vector<int> factors, int upTo) {
    int sum = 0;
    for (int i = 0; i < upTo; i++) {
        if (Factoriser::hasFactorIn(i, factors)) {
            sum += i;
        }
    }
    return sum;
};

int SumCalculator::sumFibonacciMultiplesOf(vector<int> factors, int upTo) {
    int sum = 0, fibA = 1, fibB = 2;
    
    if (Factoriser::hasFactorIn(fibA, factors)) {
        sum += fibA;
    }
    
    if (Factoriser::hasFactorIn(fibB, factors)) {
        sum += fibB;
    }
    
    while (fibA + fibB <= upTo) {
        for (vector<int>::iterator it = factors.begin(); it != factors.end(); ++it) {
            
            int fib = fibA + fibB;
            
            if (Factoriser::hasFactorIn(fib, factors)) {
                sum += fib;
            }
            
            fibA = fibB;
            fibB = fib;
        }
    }
    
    return sum;
}