
#include "calculator.h"
#include "primeCalculator.h"
#include "factoriser.h"
#include "transformer.h"
#include <map>

using std::map;
using std::max_element;
using std::max;

bool isPalindromic(vector<int> vector);
void verifyIsTriangle(vector<vector<int>> triangle);
int maxTotalForVerifiedTrianglePath(vector<vector<int>> verifiedTriangle);

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

vector<int> Calculator::sumOfVectors(vector<int> vector1, vector<int> vector2) {
    vector<int> sumOfVectors;
    
    if (vector1.size() == 0) {
        sumOfVectors = vector2;
        return sumOfVectors;
    } else if (vector2.size() == 0) {
        sumOfVectors = vector1;
        return sumOfVectors;
    }
    
    bool vector1IsLargerThanVector2 = vector1.size() > vector2.size();
    
    sumOfVectors = vector1IsLargerThanVector2 ? vector1 : vector2;
    vector<int> smallerVector = vector1IsLargerThanVector2 ? vector2 : vector1;
    
    long smallerVectorSize = smallerVector.size();
    for(int i = 0; i < smallerVectorSize; ++i) {
        long sumEntry = sumOfVectors.size() - smallerVectorSize + i;
        sumOfVectors[sumEntry] += smallerVector[i];
        
        unsigned long k = sumEntry;
        while (sumOfVectors[k] >= 10) {
            int tens = sumOfVectors[k] / 10;
            
            sumOfVectors[k] = sumOfVectors[k] % 10;
            if (k == 0) {
                sumOfVectors.insert(sumOfVectors.begin(), tens);
                ++k;
            } else {
                sumOfVectors[k - 1] = sumOfVectors[k - 1] + tens;
            }
            
            k--;
        }
    }
    
    return sumOfVectors;
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

int Calculator::powerOf(int number, int power) {
    int result = 1;
    
    for (int i = 0; i < power; ++i) {
        result *= number;
    }
    
    return result;
}

vector<int> Calculator::powerOfAsVector (int number, int power) {
    vector<int> numberAsVector = Transformer::asVector(number);

    for (unsigned int i = 1; i < power; ++i) {
        for (unsigned int j = 0; j < numberAsVector.size(); ++j) {

            numberAsVector[j] = numberAsVector[j] * number;

            unsigned int k = j;
            while (numberAsVector[k] >= 10) {
                int tens = numberAsVector[k] / 10;

                numberAsVector[k] = numberAsVector[k] % 10;
                if (k == 0) {
                    numberAsVector.insert(numberAsVector.begin(), tens);
                    ++j;
                    ++k;
                } else {
                    numberAsVector[k - 1] = numberAsVector[k - 1] + tens;
                }
                
                k--;
            }
        }
    }

    return numberAsVector;
}

// Concatenates two numbers e.g. conc(11,27)=1127
int Calculator::conc(int a, int b) {
    int c = b;
    while (c > 0) {
        a *= 10;
        c /= 10;
    }
    return a + b;
}

long Calculator::lowestCommonDenominator(vector<int> numbers) {
    int maxNumber = *max_element(numbers.begin(), numbers.end());
    
    vector<int> primes = PrimeCalculator::buildVectorOfPrimesBelow(maxNumber + 1);
    map<int, vector<long>> factors;
    
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        factors[*it] = Factoriser::factorise(*it);
    }
    
    long product = 1;
    for (vector<int>::iterator primesIt = primes.begin(); primesIt != primes.end(); ++primesIt) {
        int prime = *primesIt;
        int maxOfPrime = 0;
        for (map<int, vector<long>>::iterator factorsMapIt = factors.begin(); factorsMapIt != factors.end(); ++factorsMapIt) {
            vector<long> vectorOfFactors = factorsMapIt->second;
            int numberOfPrime = (int) count(vectorOfFactors.begin(), vectorOfFactors.end(), prime);
            
            maxOfPrime = numberOfPrime > maxOfPrime ? numberOfPrime : maxOfPrime;
        }
        product *= powerOf(prime, maxOfPrime);
    }
    
    return product;
}

int Calculator::maxTotalForTrianglePath(vector<vector<int>> triangle) {
    verifyIsTriangle(triangle);
    return maxTotalForVerifiedTrianglePath(triangle);
}

void verifyIsTriangle(vector<vector<int>> triangle) {
    for (int i = 0; i < triangle.size(); ++i) {
        if (triangle[i].size() != i + 1) {
            throw std::runtime_error("vector must be triangle shape");
        }
    }
}

int maxTotalForVerifiedTrianglePath(vector<vector<int>> triangle) {
    if (triangle.size() == 2) {
        int topPosition = triangle[0][0];
        int bottomPosition1 = triangle[1][0];
        int bottomPosition2 = triangle[1][1];
        return topPosition + max(bottomPosition1, bottomPosition2);
    } else {
        vector<vector<int>> smallerTriangle = triangle;
        
        vector<int> bottomRow = smallerTriangle[smallerTriangle.size() - 1];
        smallerTriangle.pop_back();
        
        vector<int> secondFromBottomRow = smallerTriangle[smallerTriangle.size() - 1];
        
        for (int i = 0; i < secondFromBottomRow.size(); ++i) {
            smallerTriangle[smallerTriangle.size() - 1][i] = secondFromBottomRow[i] + max(bottomRow[i], bottomRow[i + 1]);
        }
        
        return maxTotalForVerifiedTrianglePath(smallerTriangle);
    }
}



