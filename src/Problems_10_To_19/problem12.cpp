//http://projecteuler.net/problem=12

#include "problem12.h"
#include "factoriser.h"
#include <iostream>

using std::cout;
using std::endl;

const Problem12 Problem12::INSTANCE = Problem12();


void Problem12::run() const {
    long triangleNumber = 1;
    long numberOfDivisors = 1;
    
    int j = 2;
    while(numberOfDivisors < 501) {
        triangleNumber += j;
        numberOfDivisors = Factoriser::numberOfDivisorsFor(triangleNumber);
        ++j;
    }
    
    cout << "First Triangle Number To Have Over 500 Divisors Is: " << triangleNumber << endl << endl;
}




