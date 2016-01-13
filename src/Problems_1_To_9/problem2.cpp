//http://projecteuler.net/problem=2

#include "problem2.h"
#include "calculator.h"
#include <iostream>
#include <ctime>

using std::clock_t;
using std::cout;
using std::endl;

const Problem2 Problem2::INSTANCE = Problem2();

void Problem2::run() const {
    vector<int> factors = {2};
    
    Calculator calculator = Calculator::instace();
    
    cout << "By considering the terms in the Fibonacci sequence whose values do not exceed four million, the sum of the even-valued terms is: " << endl;
    cout << calculator.sumFibonacciMultiplesOf(factors, 4000000) << endl << endl;
}
