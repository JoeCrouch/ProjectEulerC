//http://projecteuler.net/problem=5

#include "problem5.h"
#include "calculator.h"
#include "factoriser.h"
#include <map>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::map;

const Problem5 Problem5::INSTANCE = Problem5();

void Problem5::run() const {
    vector<int> numbers;

    for (int i = 2; i <= 21; ++i) {
        numbers.push_back(i);
    }

    long lowestCommonDenominator = Calculator::lowestCommonDenominator(numbers);

    cout << "The lowest common denominator of the numbers 1,2,..,20 is: " << lowestCommonDenominator << endl << endl;
}
