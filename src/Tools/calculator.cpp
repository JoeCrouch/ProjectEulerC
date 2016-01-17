
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
    for (unsigned int i = 0; i < vector.size() / 2; ++i) {
        if (vector[i] != vector[vector.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool Calculator::isPrime(int n) {
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
        for (int i = 7; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
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

vector<int> Calculator::powerOfAsVector (int number, int power) {
    vector<int> numberAsVector = Transformer::asVector(number);

    for (int i = 1; i < power; ++i) {
        for (unsigned int j = 0; j < numberAsVector.size(); ++j) {

            numberAsVector[j] = numberAsVector[j] * number;

            if (numberAsVector[j] >= 10) {
                int tens = numberAsVector[j] / 10;

                numberAsVector[j] = numberAsVector[j] % 10;
                if (j == 0) {
                    numberAsVector.insert(numberAsVector.begin(), tens);
                    ++j;
                } else {
                    numberAsVector[j - 1] = numberAsVector[j - 1] + tens;
                }
            }
        }
    }

    return numberAsVector;
}

