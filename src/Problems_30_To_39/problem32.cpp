//http://projecteuler.net/problem=32

#include "problem32.h"
#include "calculator.h"
#include "factoriser.h"
#include "transformer.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::find;

bool isPandigital(long number);

const Problem32 Problem32::INSTANCE = Problem32();

void Problem32::run() const {
    int sum = 0;
    vector<int> products;
    
    for (int i = 2; i <= 98; ++i) {
        
        int min = (i > 9) ? 123 : 1234;
        int max = 9876 / i + 1;
        
        for (int j = min; j <= max; ++j) {
            int mult = i * j;
            
            if (find(products.begin(), products.end(), mult) == products.end() &&
                isPandigital(Calculator::conc(i, j, mult))) {
                products.push_back(mult);
                sum += mult;
            }
        }
    }
    
    cout << "Sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital is : "
    << sum << endl << endl;
}

bool isPandigital(long number) {
    vector<int> asVector = Transformer::asVector(number);
    
    if (asVector.size() != 9) {
        return false;
    }
    
    for (int i = 1; i < 10; ++i) {
        if (find(asVector.begin(), asVector.end(), i) == asVector.end()) {
            return false;
        }
    }
    
    return true;
}

