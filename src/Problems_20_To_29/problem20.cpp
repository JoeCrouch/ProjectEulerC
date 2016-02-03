//http://projecteuler.net/problem=20

#include "problem20.h"
#include "calculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem20 Problem20::INSTANCE = Problem20();

void Problem20::run() const {
    vector<int> factorial = Calculator::factorialAsVector(100);

    int sum = 0;
    for (vector<int>::iterator it = factorial.begin(); it != factorial.end(); ++it) {
        sum += *it;
    }

    cout << "The sum of the digits in 100! is: " << sum << endl << endl;
}




