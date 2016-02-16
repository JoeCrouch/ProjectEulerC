//http://projecteuler.net/problem=38

#include "problem38.h"
#include "calculator.h"
#include "numberCharacteristic.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem38 Problem38::INSTANCE = Problem38();

void Problem38::run() const {
    int upperBound = 10000;
    long largest1To9ProductPandigitalNumber = 0;
    
    for (int i = 1; i < upperBound; ++i) {
        long concMultipliers = i;
        
        int j = 2;
        while (NumberCharacteristic::lengthOf(concMultipliers) < 9) {
            concMultipliers = Calculator::conc(concMultipliers, i * j);
            j++;
        }
        
        if (NumberCharacteristic::is1To9Pandigital(concMultipliers) && concMultipliers > largest1To9ProductPandigitalNumber) {
            largest1To9ProductPandigitalNumber = concMultipliers;
        }
    }
    
    cout << "The Largest 1 To 9 Product Pandigital Number is: " << largest1To9ProductPandigitalNumber << endl << endl;
    
}





