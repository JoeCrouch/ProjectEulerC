//http://projecteuler.net/problem=21

#include "problem21.h"
#include "factoriser.h"
#include "calculator.h"
#include "primeCalculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

long sumProperDivisors(long n);

const Problem21 Problem21::INSTANCE = Problem21();

void Problem21::run() const {
    int max = 9999;
    long sum = 0;

    for (int i = 1; i <= max; ++i) {
        if (PrimeCalculator::isPrime(i)) {
            continue;
        }

        long sumOfProperDivisors = sumProperDivisors(i);
        long sumOfPairsProperDivisors = sumProperDivisors(sumOfProperDivisors);

        if (sumOfPairsProperDivisors == i && i != sumOfProperDivisors) {
            sum += i;
        }
    }

    cout << "The Sum Of Amicable Numbers Below " << max + 1 << " is: " << sum << endl << endl;
}

long sumProperDivisors(long n) {
    vector<long> divisors = Factoriser::divisorsFor(n);

    long sumOfDivisors = Calculator::sum(divisors);

    return sumOfDivisors - n;
}




