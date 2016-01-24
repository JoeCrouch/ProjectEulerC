//http://projecteuler.net/problem=16

#include "problem16.h"
#include "printer.h"
#include "transformer.h"
#include "calculator.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;

const Problem16 Problem16::INSTANCE = Problem16();

vector<int> powerOfAsVector(int number,int power);

void Problem16::run() const {
    vector<int> numberAsVector = Calculator::powerOfAsVector(2, 1000);
    int sum = 0;

    for (unsigned int i = 0; i < numberAsVector.size(); ++i) {
        sum += numberAsVector[i];
    }

    cout << "2 ^ 1000 = " << endl;

    Printer::vecPrint(numberAsVector, 1);

    cout << "The sum of these digits is: " << endl;
    cout << sum << endl << endl;
}
