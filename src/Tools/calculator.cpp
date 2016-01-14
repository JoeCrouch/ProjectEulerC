
#include "calculator.h"
#include "factoriser.h"
#include "transformer.h"

bool isPalindromic(vector<int> vector);

/*
 * Calculates the sum of all integers less than @upTo that have at least one factor in @factors. 
 */
int Calculator::sumMulitplesOf(vector<int> factors, int upTo) {
    int sum = 0;
    for (int i = 0; i < upTo; i++) {
        if (Factoriser::hasFactorIn(i, factors)) {
            sum += i;
        }
    }
    return sum;
};

int Calculator::sumFibonacciMultiplesOf(vector<int> factors, int upTo) {
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

bool Calculator::isPalindromic(int n) {
    vector<int> nAsVector = Transformer::asVector(n);
    
    return ::isPalindromic(nAsVector);
}

bool isPalindromic(vector<int> vector) {
    for (int i = 0; i < vector.size() / 2; ++i) {
        if (vector[i] != vector[vector.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

long Calculator::sumNumbersFromTo(int from, int to) {
    long sum = 0;
    
    for (int i = from; i <= to; ++i) {
        sum += i;
    }
    
    return sum;
    
}

long Calculator::sumSquaresFromTo(int from, int to) {
    long sum = 0;
    
    for (int i = from; i <= to; ++i) {
        sum += (i * i);
    }
    
    return sum;
    
}

