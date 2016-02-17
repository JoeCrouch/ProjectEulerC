//http://projecteuler.net/problem=41

#include "problem41.h"
#include "calculator.h"
#include "primeCalculator.h"
#include "transformer.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem41 Problem41::INSTANCE = Problem41();

void Problem41::run() const {
    int maxPandigitalPrime = 0;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    long permutationNumber = Calculator::factorial(numbers.size());
    while (maxPandigitalPrime == 0) {
        vector<int> pandigitalAsVector = Calculator::getLexPermutation(numbers, permutationNumber);
        int pandigitalNumber = Transformer::asNumber(pandigitalAsVector);
        
        if (PrimeCalculator::isPrime(pandigitalNumber)) {
            maxPandigitalPrime = pandigitalNumber;
        }
        
        permutationNumber--;
        
        if (permutationNumber == 0) {
            numbers.pop_back();
            permutationNumber = Calculator::factorial(numbers.size());
        }
        
    }
    
    cout << "Max pandigital prime is: " << maxPandigitalPrime << endl << endl;

}

