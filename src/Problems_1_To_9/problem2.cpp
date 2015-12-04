//http://projecteuler.net/problem=2

#include "problem2.h"
#include <iostream>
#include <ctime>

using std::clock_t;
using std::cout;
using std::endl;

const Problem2 Problem2::INSTANCE = Problem2();

void Problem2::run() const {
    // TODO: Extract tool for generic fibonacci
    int sum = 2, fib2 = 2, fib1 = 1, fib = 0;
    while(fib1 + fib2 <= 4000000)
    {
        fib = fib1 + fib2;
        if (fib % 2 == 0){
            sum = sum + fib;
        }
        fib1 = fib2;
        fib2 = fib;
    }
    cout << "By considering the terms in the Fibonacci sequence whose values do not exceed four million, the sum of the even-valued terms is: " << endl;
    cout << "Sum = " << sum << endl << endl;
}
