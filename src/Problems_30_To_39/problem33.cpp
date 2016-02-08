//http://projecteuler.net/problem=33

#include "problem33.h"
#include "calculator.h"
#include "fraction.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem33 Problem33::INSTANCE = Problem33();

void Problem33::run() const {
    vector<int> numerators;
    vector<int> denominators;
    
    for (int i = 11; i < 100; ++i) {
        if (i % 10 == 0) {
            continue;
        }
        
        int firstDigitI = i / 10;
        int secondDigitI = i % 10;
        
        for (int j = i + 1; j < 100; ++j) {
            if (j % 10 == 0) {
                continue;
            }
            
            Fraction fraction = Fraction (i, j);
            
            int firstDigitJ = j / 10;
            int secondDigitJ = j % 10;
            
            bool isValid = false;
            if (firstDigitI == secondDigitJ && fraction == Fraction (secondDigitI, firstDigitJ)) {
                isValid = true;
            } else if (secondDigitI == firstDigitJ && fraction == Fraction (firstDigitI, secondDigitJ)) {
                isValid = true;
            }
            
            if (isValid) {
                numerators.push_back(i);
                denominators.push_back(j);
            }
        }
    }
    
    Fraction product = Fraction(Calculator::product(numerators), Calculator::product(denominators));
    
    cout << "Lowest Common Multiple of Denominators is: " << product.getDenominator() << endl << endl;
}


