
#include "sumCalculator.h"

bool hasFactorIn(int number, vector<int> factors);


/*
 * Calculates the sum of all integers less than @upTo that have at least one factor in @factors. 
 */
int SumCalculator::sumMulitplesOf(vector<int> factors, int upTo) {
    int sum = 0;
    for (int i = 0; i < upTo; i++) {
        if (hasFactorIn(i, factors)) {
            sum += i;
        }
    }
    return sum;
};

int SumCalculator::sumFibonacciMultiplesOf(vector<int> factors, int upTo) {
    int sum = 0, fibA = 1, fibB = 2;
    
    if (hasFactorIn(fibA, factors)) {
        sum += fibA;
    }
    
    if (hasFactorIn(fibB, factors)) {
        sum += fibB;
    }
    
    while (fibA + fibB <= upTo) {
        for (vector<int>::iterator it = factors.begin(); it != factors.end(); ++it) {
            
            int fib = fibA + fibB;
            
            if (hasFactorIn(fib, factors)) {
                sum += fib;
            }
            
            fibA = fibB;
            fibB = fib;
        }
    }
    
    return sum;
}

bool hasFactorIn(int number, vector<int> factors) {
    for (vector<int>::iterator it = factors.begin(); it != factors.end(); ++it) {
        if (number % *it == 0) {
            return true;
        }
    }
    
    return false;
}