//http://projecteuler.net/problem=3

#include "problem3.h"
#include "factoriser.h"
#include "printer.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

const Problem3 Problem3::INSTANCE = Problem3();

void Problem3::run() const {
    long long number = 600851475143;
    
    vector<long> primeFactors = Factoriser::factorise(number);
    cout << "Prime factors of 600851475143 are: " << endl;

    Printer::vecPrint(primeFactors);
    
    cout << "Largest Prime = " << primeFactors.back() << endl << endl;
}
