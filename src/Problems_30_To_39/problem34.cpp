//http://projecteuler.net/problem=34

#include "problem34.h"
#include "calculator.h"
#include "transformer.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem34 Problem34::INSTANCE = Problem34();

void Problem34::run() const {
    long sumOfSums = 0;
    vector<long> factorials;
    
    for (int i = 0; i < 10; ++i) {
        factorials.push_back(Calculator::factorial(i));
    }
    
    long upperLimit = 6 * factorials[9];
    
    for (int i = 10; i < upperLimit; ++i) {
        
        int sum = 0;
        int num = i;
        while (num > 0) {
            sum += factorials[num % 10];
            num /= 10;
            if (sum > i) {
                break;
            }
        }
        
        if (sum == i) {
            sumOfSums += sum;
        }
    }
    
    cout << "Sum of numbers where the sum of the factorial of its digits equal itself is: " << sumOfSums << endl << endl;
}


