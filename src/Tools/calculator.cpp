
#include "calculator.h"
#include "primeCalculator.h"
#include "factoriser.h"
#include "transformer.h"
#include <map>
#include <algorithm>
#include <stdexcept>

using std::map;
using std::max_element;
using std::max;
using std::invalid_argument;

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

long Calculator::sumProperDivisors(long n) {
    vector<long> divisors = Factoriser::divisorsFor(n);
    
    long sumOfDivisors = Calculator::sum(divisors);
    
    return sumOfDivisors - n;
}

long Calculator::sum(vector<long> numbers) {
    long sum = 0;

    for (vector<long>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        sum += *it;
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

int Calculator::product(vector<int> numbers) {
    int product = 1;
    
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        product *= *it;
    }
    
    return product;
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

    for (int i = 1; i < power; ++i) {
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
long Calculator::conc(long a, long b) {
    long c = b;
    while (c > 0) {
        a *= 10;
        c /= 10;
    }
    return a + b;
}

long Calculator::conc(long a, long b, long c) {
    return conc(conc(a, b), c);
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

long Calculator::factorial(long number) {
    return (number == 0 || number == 1) ? 1 : factorial(number - 1) * number;
}

vector<int> Calculator::factorialAsVector(int number) {
    vector<int> numberAsVector = Transformer::asVector(number);

    for (int i = number - 1; i > 0; --i) {
        for (unsigned int j = 0; j < numberAsVector.size(); ++j) {

            numberAsVector[j] = numberAsVector[j] * i;

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

vector<int> Calculator::getLexPermutation(vector<int> numbers, long permutationNumber) {
    long size = numbers.size();
    if (permutationNumber > Calculator::factorial(size)) {
        throw invalid_argument("Cannot Get Permutation Number Greater Than Total Number Of Permutations.");
    }
    vector<int> permutation;
    vector<int> remainingNumbers = numbers;
    
    sort(numbers.begin(), numbers.end());
    
    for (int i = 1; i < size; ++i) {
        long factorial = Calculator::factorial(size - i);
        
        int count = 0;
        while (permutationNumber > factorial) {
            permutationNumber -= factorial;
            count++;
        }
        
        permutation.push_back(remainingNumbers[count]);
        remainingNumbers.erase(remainingNumbers.begin() + count);
    }
    
    permutation.push_back(remainingNumbers[0]);
    
    return permutation;
}

vector<long> Calculator::getTriangleNumbersLessThanOrEqualTo(long maxWordScore) {
    vector<long> triangleNumbers;
    
    int diff = 2;
    long triangleNumber = 1;
    while (triangleNumber <= maxWordScore) {
        triangleNumbers.push_back(triangleNumber);
        triangleNumber += diff;
        diff++;
    }
    
    return triangleNumbers;
}



