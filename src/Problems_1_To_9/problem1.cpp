//http://projecteuler.net/problem=1

#include "problem1.h"
#include <iostream>
#include "sumCalculator.h"

using std::cout;
using std::endl;

const Problem1 Problem1::INSTANCE = Problem1();

void Problem1::run() const {
    vector<int> factors = {3, 5};
    
    SumCalculator calculator = SumCalculator::instace();
    cout << "The sum of all the multiples of 3 or 5 below 1000 is: " << endl;
    cout << calculator.sumMulitplesOf(factors, 1000) << endl << endl;
}
