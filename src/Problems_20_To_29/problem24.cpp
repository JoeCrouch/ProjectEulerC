//http://projecteuler.net/problem=24

#include "problem24.h"
#include "printer.h"
#include "calculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem24 Problem24::INSTANCE = Problem24();

void Problem24::run() const {
    int permutationNumber = 1000000;
    vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vector<int> permutation = Calculator::getLexPermutation(numbers, permutationNumber);
    
    cout << "The millionth lexicographic permutaion for 0 - 9 is: " << endl;
    Printer::vecPrint(permutation);
    cout << endl;
}


