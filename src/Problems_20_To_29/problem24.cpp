//http://projecteuler.net/problem=24

#include "problem24.h"
#include "printer.h"
#include "calculator.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::invalid_argument;

vector<int> getLexPermutation(vector<int> numbers, int permutationNumber);

const Problem24 Problem24::INSTANCE = Problem24();

void Problem24::run() const {
    int permutationNumber = 1000000;
    vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vector<int> permutation = getLexPermutation(numbers, permutationNumber);
    
    cout << "The millionth lexicographic permutaion for 0 - 9 is: " << endl;
    Printer::vecPrint(permutation);
    cout << endl;
}

vector<int> getLexPermutation(vector<int> numbers, int permutationNumber) {
    long size = numbers.size();
    if (permutationNumber > Calculator::factorial(size)) {
        throw invalid_argument("Cannot Get Permutation Number Greater Than Total Number Of Permutations.");
    }
    vector<int> permutation;
    vector<int> remainingNumbers = numbers;
    
    sort(numbers.begin(), numbers.end());
    
    for (int i = 1; i < size; ++i) {
        long factorial = Calculator::factorial(size - i);
        
        int count = 0;
        while (permutationNumber > factorial) {
            permutationNumber -= factorial;
            count++;
        }
        
        permutation.push_back(remainingNumbers[count]);
        remainingNumbers.erase(remainingNumbers.begin() + count);
    }
    
    permutation.push_back(remainingNumbers[0]);
    
    return permutation;
}


