//http://projecteuler.net/problem=6

#include "problem6.h"
#include "calculator.h"
#include <iostream>

using std::cout;
using std::endl;

const Problem6 Problem6::INSTANCE = Problem6();

void Problem6::run() const {
    Calculator calc = Calculator::instace();
    long sumOfFirst100Numbers = calc.sumNumbersFromTo(1, 100);
    long sumOfSquaresOfFirst100Numbers = calc.sumSquaresFromTo(1, 100);
    
    cout << "The sum of the squares of the first 100 natural numbers is:" << endl;
    cout << sumOfSquaresOfFirst100Numbers << endl << endl;
    
    long squareOfSumOfFirst100Numbers = sumOfFirst100Numbers * sumOfFirst100Numbers;
    cout << "The square of the sum of the first 100 natural numbers is:" << endl;
    cout << squareOfSumOfFirst100Numbers << endl << endl;
    
    long k = squareOfSumOfFirst100Numbers - sumOfSquaresOfFirst100Numbers;
    cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is:" << endl;
    cout << k << endl << endl;
}
