//http://projecteuler.net/problem=29

#include "problem29.h"
#include "calculator.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::pow;

const Problem29 Problem29::INSTANCE = Problem29();

void Problem29::run() const {
    int max = 100;
    vector<double> powers;
    
    for (int a = 2; a <= max; ++a) {
        for (int b = 2; b <= max; ++b) {
            double power = pow(a, b);
            if (find(powers.begin(), powers.end(), power) == powers.end()) {
                powers.push_back(power);
            }
        }
    }
    
    cout << "Total Distinct Results For a^b with 2 <= a,b <= 100 is: " << powers.size() << endl << endl;
}

