//http://projecteuler.net/problem=10

#include "problem10.h"
#include "calculator.h"
#include <iostream>

using std::cout;
using std::endl;

int isPrime10(long int n);

const Problem10 Problem10::INSTANCE = Problem10();

void Problem10::run() const {
    long sum = 2;
    Calculator calc = Calculator::instace();

    for (long number = 3; number < 2000000; number += 2) {
        if (calc.isPrime(number)) {
            sum += number;
        }
    }

    cout << "The sum of all the primes below two million is:" << endl;
    cout << sum << endl << endl;
}
