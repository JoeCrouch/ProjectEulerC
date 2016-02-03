//http://projecteuler.net/problem=25

#include "problem25.h"
#include "calculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem25 Problem25::INSTANCE = Problem25();

void Problem25::run() const {
    
    vector<int> fibA = {1};
    vector<int> fibB = {1};
    
    int index = 2;
    while (fibA.size() < 1000) {
        vector<int> sum = Calculator::sumOfVectors(fibA, fibB);
        
        fibB = fibA;
        fibA = sum;
        
        index++;
    }
    
    cout << "Index Of First Fibonacci Number With 1000 Digits Is: " << index << endl << endl;
}

